#include"iniget.h"
/*这是一个conky的cpu温度的获取程序.
 	tybitsfox		2022-4-26
add:
	2022-4-27 添加对amd显卡的温度获取
	使用设备索引号区分不同的设备，
	index=0		cpu温度
	index=1		amdgpu温度
	对于使用nvidia闭源驱动的设备，索引码为2
	index=2		nvidiagpu 温度
	index=3		开源驱动显卡温度
 */
#define	amd		"amdgpu"
#define nvidia	"nvi-cmd...forget，add it later"

int main(int argc,char **argv)
{
	char ch[512],tmp[32],*c;
	int f,i,j;
	if(argc != 2)
	{
		printf("Usage:\n%s tempindex\nindex=0: coretemp\nindex=1: amd gputemp\n\
index=2: opensource gputemp\nindex=3: nvidia gputemp\n",argv[0]);
		return 0;
	}
	zero(ch);
	zero(tmp);
	j=atoi(argv[1]);
	switch(j)
	{
	case 0: //coretemp
	case 1://amd gputemp
	case 2://open source gputemp
		f=open(SFILE,O_RDONLY);
		if(f<=0)
			return 0;
		i=read(f,ch,sizeof(ch));
		if(i<=0)
			goto err_01;
		close(f);
		c=strchr(ch,'\n');
		if(j == 0)
		{
			if(c != NULL)
				c[0]=0;
			c=ch;
		}
		else //amd gpu
			c++;
		break;
	case 3://nvidia gputemp
		break;
	default:
		return 0;
	}
	f=open(c,O_RDONLY);
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
