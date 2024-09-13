#ifndef ARCHIVATOR_BY_IVAN
#define ARCHIVATOR_BY_IVAN

#include "errors_codes.h"
#include "tree_by_IVAN.h"

enum ErrorCodes formTreeWithDirectory(struct Node **tree, const char *directoryName);
char* formSubdirectoryFullName(const char *directoryName, const char *subdirectoryName);

#endif //ARCHIVATOR_BY_IVAN
