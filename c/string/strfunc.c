#include <stdio.h>
#include <string.h>

int countStr(char *string) {
	int len = 0;
	while (1) {
		if (*string != '\0')
			len++;
		else
			break;
		string++;
	}
	return len;
}

int main() {
	char str1[12] = "hello";
	char str2[12] = "world";
	char str3[12];
	int len;

	strcpy(str3, str1);
	printf("strcpy %s\n", str3);

	strcat(str1, str2);
	printf("strcat %s\n", str1);

	len = strlen(str1);
	printf("%d %ld %d\n", len, sizeof(str1)/sizeof(*str1), countStr(str1));
	return 0;
}
