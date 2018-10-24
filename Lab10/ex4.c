#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>

void main()
{
    //freopen("ex4.txt",'w',stdout);
    DIR *dirp = opendir("/tmp");
    if (dirp == NULL)
    {
        printf("Directory is not found\n");
        return;
    }

    char *f1n = "file1";
    int len = strlen(f1n);
    struct dirent *entry_p;
    while ((entry_p = readdir(dirp)) != NULL)
    {
        // if (strlen(entry_p->d_name) == len && strcmp(entry_p->d_name, f1n))
        // {
        //     // closedir(dirp);
        // }

        struct stat buf;
        stat(entry_p->d_name, &buf);

        printf("%s, #hardlinks = %lu\n", entry_p->d_name, buf.st_nlink);
    }
    closedir(dirp);
}