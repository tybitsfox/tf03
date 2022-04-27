#include"iniget.h"
/*update 2022-4-27
  add the code to get gpu(amd opensource) temp dir

 */
int main(int argc,char **argv)
{
	char path[3][512],ch[64];
	int f,i,j;
	zero(path[2]);
	for(i=0;i<5;i++)
	{
		zero(path[0]);zero(ch);
		snprintf(path[0],sizeof(path),"%s%d/name",Ddir,i);
		f=open(path[0],O_RDONLY);
		if(f<=0)
			break;
		j=read(f,ch,32);
		if(j<=0)
		{close(f);break;}
		close(f);
		if(strncmp(ch,"coretemp",8) == 0) //core
		{
			zero(path[1]);
			snprintf(path[1],sizeof(path[1]),"%s%d/temp1_input\n",Ddir,i);
			continue;
		}
		if(strncmp(ch,"amdgpu",6) == 0) //amdgpu
		{
			zero(path[2]);
			snprintf(path[2],sizeof(path[2]),"%s%d/temp1_input",Ddir,i);
			continue;
		}
		if(strncmp(ch,"acpitz",6) == 0) //?? incorrect
		{
			if(path[2][0] != 0)
				continue;
			snprintf(path[2],sizeof(path[2]),"%s%d/temp1_input",Ddir,i);
			continue;
		}
	}
	f=open(SFILE,O_RDWR|O_CREAT,0644);
	if(f<=2)
		return 0;
	write(f,path[1],strlen(path[1]));
	write(f,path[2],strlen(path[2]));
	return 0;
}



