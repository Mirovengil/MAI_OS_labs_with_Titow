#include "archivator_by_IVAN.h"
#include <dirent.h>		// библиотека для работы с папками 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*****************************
 * 
 * Большое TODO: приватным функциям можно возвращать, что угодно, потому что они сокрыты от
 * всех, кроме меня, а вот библиотечные функции должны возвращать строго коды ошибок
 * 
 * 
 * Ещё большое TODO: сделай все типы строгими (в духе: int32_t)
*****************************/

// приватные функции, которые не стоит выставлять в .h файл
char* formSubdirectoryFullName(const char *directoryName, const char *subdirectoryName);
char* formFileFullName(const char *directoryName, const char *fileName);
enum ErrorCodes getBytesArrayFromFile(const char *fullFilename, char **bytesArray, long *lengthOfArray);
void codeTreeAsArrayOfBytes(struct Node *tree, char **startOfArray, 
	int *shift, int *sizeOfArray);

const char codesOfTypesOfNodes[NUMBER_OF_NODE_TYPES] = {0, 1};

#include <stdio.h>	// ну кто бы сомневался, что придётся дебажить...
enum ErrorCodes formTreeWithDirectory(struct Node **tree, const char *directoryName)
{
	// перед тем, как выделять память под дерево и начинать забивать в него директорию,
	// надо убедиться, что пользователь не мудак и указал правильную директорию
	DIR *directory;
    struct dirent *currentObject;

    directory = opendir(directoryName);
    if (!directory) {
        return DIRECTORY_NOT_OPENED;
    };

	// создаём дерево; первая вершина, очевидно, папка
	*tree = createNewNode(directoryName, FOLDER_NODE);

    while ( (currentObject = readdir(directory)) != NULL) {

		// скрытые папки и файлы не рассматриваем
		if (currentObject->d_name[0] == '.')
			continue;

		if (currentObject->d_type == 4)
		{
			// добавляем в дерево FOLDER_NODE
			char *subdirectoryFullName = formSubdirectoryFullName(directoryName, currentObject->d_name);

			// TODO:
			// ВОТ ЭТО МЕСТО НАПИСАНО ЧЕРЕЗ ЖОПУ!!!!
			// надо починить!!!!!
			struct Node *tmp = createNewNode(currentObject->d_name, FOLDER_NODE);
			formTreeWithDirectory(&tmp, subdirectoryFullName);
			addNewObjectToFolderNode(tmp, *tree);
			// enum ErrorCodes errCode = formTreeWithDirectory(&tmp, subdirectoryFullName);
			// if (errCode != OK)
				// return errCode;
			
			free(subdirectoryFullName);
		}
		else
		{
			// добавляем в дерево FILE_NODE
			struct Node* fileNode = createNewNode(currentObject->d_name, FILE_NODE);
			addNewObjectToFolderNode(fileNode, *tree);

			// формируем имя файла целиком
			char *fileFullName = formFileFullName(directoryName, currentObject->d_name);

			// считываем его содержимое
			// TODO: доделать код ошибки, который возвращает ф-я getBytesArrayFromFile
			getBytesArrayFromFile(fileFullName, &fileNode->data, &fileNode->dataSize);
		}
    };

    closedir(directory);

	return OK;
};

char* formSubdirectoryFullName(const char *directoryName, const char *subdirectoryName)
{
	
	char *subdirectoryFullName = malloc(sizeof(char) * (strlen(directoryName) + strlen(subdirectoryName) + 3)); 
	
	// первая часть: полный путь до поддиректории
	strncpy(subdirectoryFullName, directoryName, strlen(directoryName));
	subdirectoryFullName[strlen(directoryName)] = '/';
	
	// вторая часть: само название поддиректории
	strncpy(subdirectoryFullName+strlen(directoryName), subdirectoryName, strlen(subdirectoryName));
	subdirectoryFullName[strlen(directoryName) + strlen(subdirectoryName)] = '/';
	subdirectoryFullName[strlen(directoryName) + strlen(subdirectoryName) + 1] = '\0';
	
	return subdirectoryFullName;
};

char* formFileFullName(const char *directoryName, const char *fileName)
{
	char *fileFullName = malloc(sizeof(char) * (strlen(directoryName) + strlen(fileName) + 2)); 
	
	// первая часть: полный путь до файла
	strncpy(fileFullName, directoryName, strlen(directoryName));
	fileFullName[strlen(directoryName)] = '/';
	
	// вторая часть: само название файла
	strncpy(fileFullName+strlen(directoryName), fileName, strlen(fileName));
	fileFullName[strlen(directoryName) + strlen(fileName)] = '\0';
	
	return fileFullName;
};

enum ErrorCodes getBytesArrayFromFile(const char *fullFilename, char **bytesArray, long *lengthOfArray)
{
	FILE *fIn;

	fIn = fopen(fullFilename, "rb");

	fseek(fIn, 0, SEEK_END);
	

	*lengthOfArray = ftell(fIn);
	rewind(fIn);

	*bytesArray = malloc(*lengthOfArray * sizeof(char));
	fread(*bytesArray, *lengthOfArray, 1, fIn);
	fclose(fIn);

	return OK;
};

// кодирует дерево как массив байтов и возвращает указатель на оный массив 
void codeTreeAsArrayOfBytes(struct Node *tree, char **startOfArray, 
	int *shift, int *sizeOfArray)
{
	printf("OK1\n");
	//printf("OK4\n");
	//printf("OK5\n");

	// основная информация об узле
	long sizeOfCodedNodeInBytes = 0;
	long sizeOfCodedNodeDataInBytes = 0;
	sizeOfCodedNodeInBytes += sizeof(char);		// тип Node: файл или папка?
	sizeOfCodedNodeInBytes += sizeof(int);		// длина имени (названия)
	sizeOfCodedNodeInBytes += strlen(tree->name) * sizeof(char);	// имя файла/папки
	sizeOfCodedNodeInBytes += sizeof(long);		// число объектов в папке / длина файла (в зависимости от типа)
	
	// для файла : надо выделить память под содержание файла
	sizeOfCodedNodeDataInBytes += (tree->type == FILE_NODE) * sizeof(char) * tree->dataSize;

	char signatureOfNode = codesOfTypesOfNodes[tree->type];
	int lengthOfNodesName = strlen(tree->name);

	// выделяем память под запись текущего узла
	*sizeOfArray += sizeOfCodedNodeInBytes;
	printf("header info size in bytes : %d\n", sizeOfCodedNodeInBytes);
	printf("data info size in bytes : %d\n", sizeOfCodedNodeDataInBytes);
	printf("current array size : %d\n", *sizeOfArray);
	printf("type : %d\n", signatureOfNode);
	printf("node name : %s\n", tree->name);
	*startOfArray = realloc(*startOfArray, *sizeOfArray + sizeOfCodedNodeDataInBytes);

	printf("OK2\n");

	(*startOfArray)[*shift] = signatureOfNode;
	memcpy(*startOfArray + *shift + sizeof(char), &lengthOfNodesName, sizeof(int));
	memcpy(*startOfArray + *shift  + sizeof(char) + sizeof(int), tree->name, lengthOfNodesName * sizeof(char));
	memcpy(*startOfArray + *shift  + sizeof(char) + sizeof(int) + sizeof(char) * lengthOfNodesName, 
		&tree->dataSize, sizeof(long));
	
	*shift += sizeOfCodedNodeInBytes; 
	
	printf("OK3\n");


	// дальше -- опять раздвоение логики: 
	// 1. для файла -- просто печатаем его байты подряд
	// 2. для папки -- рекурсивно печатаем её содержимое
	if (tree->type == FILE_NODE)
	{
		memcpy(*startOfArray + *shift, 
			tree->data, sizeof(char) * tree->dataSize);
		*shift += sizeof(char) * sizeOfCodedNodeDataInBytes;
		*sizeOfArray += sizeof(char) * sizeOfCodedNodeDataInBytes;
		// TODO : а схера ли, извиняюсь, я сделал shift и sizeOfArray -- разными выражениями?..
	}

	if (tree->type == FOLDER_NODE)
		for(int i = 0; i < tree->dataSize; ++i)
			codeTreeAsArrayOfBytes(((struct Node**)tree->data)[i], startOfArray, shift, sizeOfArray);


};

void saveArrayOfBytesToFile(char *arrayOfBytes, int length, char *fileName)
{
	FILE *fOut = fopen(fileName, "wb");

	//  TODO : сделай единый стандарт проверок и подгони эту хрень под него
	if (fOut == NULL)
	{
		printf("Файл не открылся!!1!111!\n");
		return;
	}

	fwrite(arrayOfBytes, sizeof(char), length-1, fOut);
	fclose(fOut);
}
