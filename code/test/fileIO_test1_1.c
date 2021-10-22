#include "syscall.h"

int main(void)
{
	char test[] = "abcdefghijklmnopqrstuvwxyz";
	int success= Create("file1.test");
	OpenFileId fid;
	int i;
	if (success != 1) MSG("Failed on creating file");
	fid = Open("file1.test");
	if (fid < 0) MSG("Failed on opening file");

    for (i = 0; i < 26; ++i) {
		int count = Write(test + i, 1, fid+1);
		if (count != -1) MSG("did not handle wrong fid");
	}
	
	for (i = 0; i < 26; ++i) {
		int count = Write(test + i, 1, fid);
		if (count != 1) MSG("Failed on writing file");
	}
       
	success = Close(fid);
	if (success != 1) MSG("Failed on closing file");

    //write on closed file
    for (i = 0; i < 26; ++i) {
		int count = Write(test + i, 1, fid);
		if (count != -1) MSG("did not handle un open file");
	}

	MSG("Success on writing test");
	Halt();
}