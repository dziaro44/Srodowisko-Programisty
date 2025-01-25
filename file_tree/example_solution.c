#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main() {
	char name[100];
	char folder_name[200];
	char file_name[100];
	char symlink_name[200];
	
	char* txt;
	size_t buf_size = 2048;
	txt = (char *)malloc(buf_size * sizeof(char));

	int num_sets;
	scanf("%d", &num_sets);

	while (num_sets--) {
		scanf("%s", name);
		char c;
		scanf("%c", &c);
		getline(&txt, &buf_size, stdin);
		
		folder_name[0] = 0;
		strcat(folder_name, getenv("PWD"));
		int p = strlen(folder_name), q = 0, b = 0;
		folder_name[p++] = '/';
		
		for (int i = 0; i < strlen(name) ;i++) {
			if(name[i] == '/') {
				folder_name[p] = 0;
				b = 1;
			}
			if (b == 0) folder_name[p++] = name[i];
			else file_name[q++] = name[i];
		}
		file_name[q] = 0;
				
		struct stat sb;
		
		if (!(stat(folder_name, &sb) == 0 && S_ISDIR(sb.st_mode))) {
			mkdir(folder_name, S_IRWXU | S_IRWXG | S_IRWXO);
		}
		
		strcat(folder_name, file_name);
		int fid = open(folder_name, O_WRONLY | O_APPEND | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
		write(fid, txt, strlen(txt));
		close(fid);
		
		symlink_name[0] = 0;
		strcat(symlink_name, getenv("PWD"));
		strcat(symlink_name, file_name);
		strcat(symlink_name, ".symlink");
		symlink(folder_name, symlink_name);
	}

	free(txt)
}
