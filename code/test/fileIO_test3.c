#include "syscall.h"

int main(void)
{
	char test[] = "abcdefghijklmnopqrstuvwxyz";
	OpenFileId fid[21];
	int i, success;
	
	// open the non-existent file
	fid[0] = Open("non-existent.test");
	if (fid[0] != -1) MSG("why can you open the non-existent file!?");

	// check opened file limit (expect 20)
	// first create 21 files
	success= Create("file0.test");
	if (success != 1) MSG("Failed on creating file0");
	success= Create("file1.test");
	if (success != 1) MSG("Failed on creating file1");
	success= Create("file2.test");
	if (success != 1) MSG("Failed on creating file2");
	success= Create("file3.test");
	if (success != 1) MSG("Failed on creating file3");
	success= Create("file4.test");
	if (success != 1) MSG("Failed on creating file4");
	success= Create("file5.test");
	if (success != 1) MSG("Failed on creating file5");
	success= Create("file6.test");
	if (success != 1) MSG("Failed on creating file6");
	success= Create("file7.test");
	if (success != 1) MSG("Failed on creating file7");
	success= Create("file8.test");
	if (success != 1) MSG("Failed on creating file8");
	success= Create("file9.test");
	if (success != 1) MSG("Failed on creating file9");
	success= Create("file10.test");
	if (success != 1) MSG("Failed on creating file10");
	success= Create("file11.test");
	if (success != 1) MSG("Failed on creating file11");
	success= Create("file12.test");
	if (success != 1) MSG("Failed on creating file12");
	success= Create("file13.test");
	if (success != 1) MSG("Failed on creating file13");
	success= Create("file14.test");
	if (success != 1) MSG("Failed on creating file14");
	success= Create("file15.test");
	if (success != 1) MSG("Failed on creating file15");
	success= Create("file16.test");
	if (success != 1) MSG("Failed on creating file16");
	success= Create("file17.test");
	if (success != 1) MSG("Failed on creating file17");
	success= Create("file18.test");
	if (success != 1) MSG("Failed on creating file18");
	success= Create("file19.test");
	if (success != 1) MSG("Failed on creating file19");
	success= Create("file20.test");
	if (success != 1) MSG("Failed on creating file20");

	// // reopen file0
	// fid[0] = Open("file0.test");
	// if (fid < 0) MSG("Failed on opening file0");
	fid[0] = Open("file0.test");
	if (fid < 0) MSG("Failed on opening file0");
	// open over 21 identical files
	fid[1] = Open("file1.test");
	if (fid[1] < 0) MSG("Failed on opening file1");
	fid[2] = Open("file2.test");
	if (fid[2] < 0) MSG("Failed on opening file2");
	fid[3] = Open("file3.test");
	if (fid[3] < 0) MSG("Failed on opening file3");
	fid[4] = Open("file4.test");
	if (fid[4] < 0) MSG("Failed on opening file4");
	fid[5] = Open("file5.test");
	if (fid[5] < 0) MSG("Failed on opening file5");
	fid[6] = Open("file6.test");
	if (fid[6] < 0) MSG("Failed on opening file6");
	fid[7] = Open("file7.test");
	if (fid[7] < 0) MSG("Failed on opening file7");
	fid[8] = Open("file8.test");
	if (fid[8] < 0) MSG("Failed on opening file8");
	fid[9] = Open("file9.test");
	if (fid[9] < 0) MSG("Failed on opening file9");
	fid[10] = Open("file10.test");
	if (fid[10] < 0) MSG("Failed on opening file10");
	fid[11] = Open("file11.test");
	if (fid[11] < 0) MSG("Failed on opening file11");
	fid[12] = Open("file12.test");
	if (fid[12] < 0) MSG("Failed on opening file12");
	fid[13] = Open("file13.test");
	if (fid[13] < 0) MSG("Failed on opening file13");
	fid[14] = Open("file14.test");
	if (fid[14] < 0) MSG("Failed on opening file14");
	fid[15] = Open("file15.test");
	if (fid[15] < 0) MSG("Failed on opening file15");
	fid[16] = Open("file8.test");
	if (fid[16] < 0) MSG("Failed on opening file16");
	fid[17] = Open("file17.test");
	if (fid[17] < 0) MSG("Failed on opening file17");
	fid[18] = Open("file18.test");
	if (fid[18] < 0) MSG("Failed on opening file18");
	fid[19] = Open("file19.test");
	if (fid[19] < 0) MSG("Failed on opening file19");
	fid[20] = Open("file20.test");
	if (fid[20] != -1) MSG("how dare you to open more than 20 files?");
	MSG("End test open.");

	

	for(i=0; i<20; i++){
		success = Close(fid[i]);
		if (success != 1) MSG("Failed on closing file");
	}

	success = Close(fid[20]);
	if (success != -1) MSG("you close the file which is no open.XD");
	success = Close(-1);
	if (success != -1) MSG("you can close the file with wrong id");
       

	MSG("End test open/close.");

	Halt();
}

