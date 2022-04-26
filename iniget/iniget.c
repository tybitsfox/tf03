#include"iniget.h"
int main(int argc,char **argv)
{
	char path[512],ch[64];
	int f,i,j;
	for(i=0;i<5;i++)
	{
		zero(path);zero(ch);
		snprintf(path,sizeof(path),"%s%d/name",Ddir,i);
		f=open(path,O_RDONLY);
		if(f<=0)
			break;
		j=read(f,ch,32);
		if(j<=0)
		{close(f);break;}
		if(strncmp(ch,"coretemp",8) != 0)
		{close(f);continue;}
		close(f);
		zero(path);
		snprintf(path,sizeof(path),"%s%d/temp1_input",Ddir,i);
		f=open(SFILE,O_RDWR|O_CREAT,0644);
		if(f<=0)
		{return 0;}
		write(f,path,strlen(path));
		close(f);
		break;
	}
	return 0;
}



