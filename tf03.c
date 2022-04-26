#include"iniget.h"
/*这是一个conky的cpu温度的获取程序.
 	tybitsfox		2022-4-26
 */
int main(int argc,char **argv)
{
	char ch[256],tmp[32];
	int f,i;
	f=open(SFILE,O_RDONLY);
	if(f<=0)
		return 0;
	zero(ch);
	i=read(f,ch,sizeof(ch));
	if(i<=0)
		goto err_01;
	close(f);
	zero(tmp);
	f=open(ch,O_RDONLY);
	if(f<=0)
		return 0;
	i=read(f,tmp,sizeof(tmp));
	if(i<=0)
		goto err_01;
	i=atoi(tmp)/1000;
	printf("%i℃ ",i);
err_01:	
	close(f);
	return 0;
};
