#include "stdafx.h"
#include <stdlib.h>
#include <string.h>

typedef struct Teeacher
{
	char name[64];
	int age;
	char *cname;
};

int copyTeacher(Teeacher *to, Teeacher *from)
{
	//Ç³copy
	//*to = *from;
	//memcpy(to, from, sizeof(from));

	//Éîcopy
	to->cname = (char *)malloc(100);
	strcpy(to->cname, from->cname);

	return 0;
}

int main()
{
	Teeacher t1;
	Teeacher t2;

	t1.cname = (char *)malloc(100);
	strcpy(t1.cname, "sssss");


	copyTeacher(&t2, &t1);

	printf("%s \n",t2.cname);

	printf("%s \n",t1.cname);


	if (t1.cname != NULL)
	{
		free(t1.cname);
		t1.cname = NULL;
	}

	if (t2.cname != NULL)
	{
		free(t2.cname);
		t2.cname = NULL;
	}

	system("pause");
	return 0;
}