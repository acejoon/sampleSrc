/**************************************************************
* Filename    : chgNum.c
* Author      : Joon
* Date        : 20190327
* Purpose     : 10 -> 16/2/C, 16 -> 10/2/C, 2 -> 16/10/C
* Usage       :
**************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Usage ();
void InputData (char *str);
int SelectConfirmation (int sNum);

char *DecToHex (char *num, char *result);
char *DecToBin (char *num, char *result);
char *DecToChar (char *num, char *result);

char *HexToDec (char *num, char *result);
char *HexToBin (char *num, char *result);
char *HexToChar (char *data, char *result);

char *BinToHex (char *num, char *result);
char *BinToDec (char *num, char *result);
char *BinToChar (char *num, char *result);

char *CharToHex (char *data, char *result);

//#define _DEBUG_
//#define _SC_

int main (int argc, char *argv[])
{
	int i;
	int cnt = 0;
	int flag = 0;
	int chk = 0;
	int sNum;

	char inputStr [100];
	char result [100];

	while (1)
	{
		++cnt;

		if (cnt == 4)
		{
			exit (0);
		}

		Usage ();

		memset (inputStr, 0x00, sizeof (inputStr));

		printf ("Select Number : ");

		InputData (inputStr);

		for (i = 0; i < strlen (inputStr); i++)
		{
			if (48 > inputStr[i] || inputStr[i] > 57)
			{
#ifdef _DEBUG_
				printf ("(D) selectNum[%d] : %c\n", i, inputStr[i]);
#endif
				flag = -1;

				break;
			}
			else
			{
				flag = 1;
			}
		}

		if (flag > 0)
		{
			sNum = atoi (inputStr);

			if (0 > sNum || sNum > 9)
			{}
			else
			{
#ifdef _SC_
				chk = SelectConfirmation (sNum);

				if (0 > chk)
				{
					continue;
				}
				else
				{
					break;
				}
#else
				break;
#endif
			}
		}
	}

	cnt = 0;

	while (1)
	{
		++cnt;

		if (cnt == 4)
		{
			exit (0);
		}

		memset (inputStr, 0x00, sizeof (inputStr));

		printf ("Input Number : ");

		InputData (inputStr);

		for (i = 0; i < strlen (inputStr); i++)
		{
			if (inputStr[0] == '-')
			{
				printf ("Minus can not be changed...\n");

				flag = -1;

				break;
			}

			if (sNum == 1 || sNum == 2)
			{
				if (48 > inputStr[i] || inputStr[i] > 57)
				{
#ifdef _DEBUG_
					printf ("(D) %d inputNum[%d] : %c\n", __LINE__, i, inputStr[i]);
#endif
					flag = -1;

					break;
				}
				else
				{
					flag = 1;
				}
			}
			else if (sNum == 4 || sNum == 5)
			{
				if (48 > inputStr[i] || inputStr[i] > 57 && 65 > inputStr[i] || inputStr[i] > 70 && 97 > inputStr[i] || inputStr[i] > 102)
				{
#ifdef _DEBUG_
					printf ("(D) %d inputNum[%d] : %c\n", __LINE__, i, inputStr[i]);
#endif
					flag = -1;

					break;
				}
				else
				{
					flag = 1;
				}
			}
			else if (sNum == 7 || sNum == 8)
			{
				if (48 > inputStr[i] || inputStr[i] > 49)
				{
#ifdef _DEBUG_
					printf ("(D) %d inputNum[%d] : %c\n", __LINE__, i, inputStr[i]);
#endif
					flag = -1;

					break;
				}
				else
				{
					flag = 1;
				}
			}
			else if (sNum == 3 || sNum == 6 || sNum == 9)
			{
				flag = 1;
			}
		}// for end

		if (flag > 0)
		{
			break;
		}
	}// while end

	memset (result, 0x00, sizeof (result));

	switch (sNum)
	{
		case 1:
			strcpy (result, DecToHex (inputStr, result));
			printf ("Dec : %s -> Hex : %s\n", inputStr, result);
		break;

		case 2:
			strcpy (result, DecToBin (inputStr, result));
			printf ("Dec : %s -> Bin : %s\n", inputStr, result);
		break;

		case 3:
			strcpy (result, DecToChar (inputStr, result));
			printf ("Dec : %s -> Char : %s\n", inputStr, result);
		break;

		case 4:
			strcpy (result, HexToDec (inputStr, result));
			printf ("Hex : %s -> Dec : %s\n", inputStr, result);
		break;

		case 5:
			strcpy (result, HexToBin (inputStr, result));
			printf ("Hex : %s -> Bin : %s\n", inputStr, result);
		break;

		case 6:
			strcpy (result, HexToChar (inputStr, result));
			printf ("Hex : %s -> Char : %s\n", inputStr, result);
		break;

		case 7:
			strcpy (result, BinToHex (inputStr, result));
			printf ("Bin : %s -> Hex : %s\n", inputStr, result);
		break;

		case 8:
			strcpy (result, BinToDec (inputStr, result));
			printf ("Bin : %s -> Dec : %s\n", inputStr, result);
		break;

		case 9:
			strcpy (result, BinToChar (inputStr, result));
			printf ("Bin : %s -> Char : %s\n", inputStr, result);
		break;

		default:
			printf ("(E) %d Error... : %d\n", __LINE__, sNum);
			exit (-1);
		break;
	}

	return 0;
}

void Usage ()
{
	printf ("1 : 10 (Dec)  -> 16 (Hex)\n");
	printf ("2 : 10 (Dec)  ->  2 (Bin)\n");
	printf ("3 : 10 (Dec)  ->  C (Char)\n");
	printf ("4 : 16 (Hex)  -> 10 (Dec)\n");
	printf ("5 : 16 (Hex)  ->  2 (Bin)\n");
	printf ("6 : 16 (Hex)  ->  C (Char)\n");
	printf ("7 :  2 (Bin)  -> 16 (Hex)\n");
	printf ("8 :  2 (Bin)  -> 10 (Dec)\n");
	printf ("9 :  2 (Bin)  ->  C (Char)\n");
}

void InputData (char *str)
{
	char inputData [100];
	memset (inputData, 0x00, sizeof (inputData));

	fgets (inputData, sizeof (inputData), stdin);

	inputData [strlen (inputData) -1] = '\0';

	fflush (stdin);

	strcpy (str, inputData);
}

int SelectConfirmation (int sNum)
{
	char ret[2];
	memset (ret, 0x00, sizeof (ret));

	switch (sNum)
	{
		case 1:
			printf ("Decimal to Hexadecimal??? y/n : ");
			InputData (ret);

			if (!strcasecmp (ret, "Y"))
			{
				return 1;
			}
			else
			{
				return -1;
			}
		break;

		case 2:
			printf ("Decimal to Binary??? y/n : ");
			InputData (ret);

			if (!strcasecmp (ret, "Y"))
			{
				return 1;
			}
			else
			{
				return -1;
			}
		break;

		case 3:
			printf ("Decimal to Character??? y/n : ");
			InputData (ret);

			if (!strcasecmp (ret, "Y"))
			{
				return 1;
			}
			else
			{
				return -1;
			}
		break;

		case 4:
			printf ("Hexadecimal to Decimal??? y/n : ");
			InputData (ret);

			if (!strcasecmp (ret, "Y"))
			{
				return 1;
			}
			else
			{
				return -1;
			}
		break;

		case 5:
			printf ("Hexadecimal to Binary??? y/n : ");
			InputData (ret);

			if (!strcasecmp (ret, "Y"))
			{
				return 1;
			}
			else
			{
				return -1;
			}
		break;

		case 6:
			printf ("Hexadecimal to Character??? y/n : ");
			InputData (ret);

			if (!strcasecmp (ret, "Y"))
			{
				return 1;
			}
			else
			{
				return -1;
			}
		break;

		case 7:
			printf ("Binary to Hexadecimal??? y/n : ");
			InputData (ret);

			if (!strcasecmp (ret, "Y"))
			{
				return 1;
			}
			else
			{
				return -1;
			}
		break;

		case 8:
			printf ("Binary to Decimal??? y/n : ");
			InputData (ret);

			if (!strcasecmp (ret, "Y"))
			{
				return 1;
			}
			else
			{
				return -1;
			}
		break;

		case 9:
			printf ("Binary to Character??? y/n : ");
			InputData (ret);

			if (!strcasecmp (ret, "Y"))
			{
				return 1;
			}
			else
			{
				return -1;
			}
		break;

		default:
			printf ("Unknown...");
			return -1;
		break;
	}
}

char *DecToHex (char *num, char *result)
{
	int i = 0;
	int j;
	int idx = 0;
	int chk;

	unsigned long tmp = 0;

	char chgHex [100] = {0};
	char ret [100];

	tmp = atol (num);

	if (tmp == 0)
	{
		memset (ret, 0x00, sizeof (ret));
		strcpy (result, "0");

		return result;
	}

	while (tmp > 0)
	{
		switch (tmp % 16)
		{
			case 10:
				chgHex [i] = 97;
			break;

			case 11:
				chgHex [i] = 98;
			break;

			case 12:
				chgHex [i] = 99;
			break;

			case 13:
				chgHex [i] = 100;
			break;

			case 14:
				chgHex [i] = 101;
			break;

			case 15:
				chgHex [i] = 102;
			break;

			default:
				chk = tmp % 16;
				chgHex [i] = chk + 48;
			break;
		}

		tmp = tmp / 16;
		++i;
	}

	memset (ret, 0x00, sizeof (ret));

	for (j = i - 1; j >= 0; j--)
	{
		ret [idx] = chgHex [j];
		++idx;
	}
#ifdef _DEBUG_
	printf ("Dec : %s -> Hex : %s\n", num, ret);
	printf ("Dec : %s -> Hex : %x\n", num, atol (num));
#endif

	strcpy (result, ret);

	return result;
}

char *DecToBin (char *num, char *result)
{
	int i, j;
	int idx = 0;

	unsigned long tmp = 0;

	char chgBin [100] = {0};
	char ret [100];

	tmp = atol (num);

	if (tmp == 0)
	{
		memset (ret, 0x00, sizeof (ret));
		strcpy (result, "0");

		return result;
	}

	for (i = 0; tmp > 0; i++)
	{
		chgBin [i] = tmp % 2;
		tmp /= 2;
	}

	memset (ret, 0x00, sizeof (ret));

	for (j = i - 1; j >= 0; j--)
	{
		if (chgBin [j] == 0)/* Dec 48 = Char 0 */
		{
			ret [idx] = 48;
		}
		else
		{
			ret [idx] = 49;
		}

		++idx;
	}
#ifdef __DEBUG__
	printf ("Dec : %s -> Bin : %s\n", num, ret);
#endif
	strcpy (result, ret);

	return result;
}

char *DecToChar (char *num, char *result)
{
	int i;
	int j = 0;

	char buff [2];

	char tmpStr [100];
	char chgNum [100];
	char tRet [100];
	char ret [100];

	memset (tmpStr, 0x00, sizeof (tmpStr));

	for (i = 0; i < (strlen (num)); i++)
	{
		if (num[i] != 32)
		{
			tmpStr [j] = num [i];
			++j;
		}
	}

#ifdef _DEBUG_
	for (i = 0; i < strlen (tmpStr); i++)
	{
		printf ("(D) tmpStr[%d] : %c\n", i, tmpStr [i]);
	}
#endif

	memset (chgNum, 0x00, sizeof (chgNum));

	for (i = 0; i < strlen (tmpStr); i += 2)
	{
		memset (buff, 0x00, sizeof (buff));

		sprintf (buff, "%c%c", tmpStr[i], tmpStr [i+1]);
#ifdef _DEBUG_
		printf ("(D) buff : %s\n", buff);
#endif
		memset (tRet, 0x00, sizeof (tRet));

		strcpy (tRet, DecToHex (buff, tRet));
		strcat (chgNum, tRet);
	}

#ifdef _DEBUG_
		printf ("(D) chgNum : %s\n", chgNum);
#endif

	memset (ret, 0x00, sizeof (ret));
	memset (tRet, 0x00, sizeof (tRet));

	strcpy (ret, HexToChar (chgNum, ret));

#ifdef _DEBUG_
	printf ("(D) ret : %s\n", ret);
#endif
	strcpy (result, ret);

	return result;
}

char *HexToDec (char *num, char *result)
{
	int i, j, k = 0;
	int len;
	int tmp;
	int chgRet = 0;

	char chgDec [100];
	char ret [100];

	memset (chgDec, 0x00, sizeof (chgDec));

	strcpy (chgDec, num);

	len = strlen (chgDec);
#ifdef _DEBUG_
	printf ("(D) len : %d\n", len);
#endif
	for (i = len - 1; i >= 0; i--)
	{
#ifdef _DEBUG_
		printf ("chgDec[%d] : %d\n", i, chgDec [i]);
#endif
		tmp = 0;

		if (chgDec [i] >= 48 && chgDec [i] <= 57)
		{
			tmp = chgDec [i] - 48;

			for (j = 0; j < k; j++)
			{
				tmp *= 16;
			}
		}
		else if (chgDec [i] >= 97 && chgDec [i] <= 102 || chgDec [i] >= 65 && chgDec [i] <= 70)
		{
			if (chgDec [i] >= 65 && chgDec [i] <= 70)
			{
				chgDec [i] += 32;
			}

			switch (chgDec [i])
			{
				case 'a':
					tmp = 10;
				break;

				case 'b':
					tmp = 11;
				break;

				case 'c':
					tmp = 12;
				break;

				case 'd':
					tmp = 13;
				break;

				case 'e':
					tmp = 14;
				break;

				case 'f':
					tmp = 15;
				break;

				default:
					printf ("Unknown...\n");
				break;
			}

			for (j = 0; j < k; j++)
			{
				tmp *= 16;
			}
		}

		chgRet += tmp;

		++k;
	}

	memset (ret, 0x00, sizeof (ret));

	sprintf (ret, "%d", chgRet);
#ifdef __DEBUG__
	printf ("Hex : %s -> Dec : %s\n", num, ret);
#endif
	strcpy (result, ret);

	return result;
}

char *HexToBin (char *num, char *result)
{
	char chgNum [100];
	char ret [100];

	memset (chgNum, 0x00, sizeof (chgNum));

	strcpy (chgNum, HexToDec (num, chgNum));

	memset (ret, 0x00, sizeof (ret));

	strcpy (ret, DecToBin (chgNum, ret));

	strcpy (result, ret);

	return result;
}

char *HexToChar (char *data, char *result)
{
	int i;
	int j = 0;
	int k = 0;
	int len = 0;
	int buf;

	char buff [2];
	char tmpStr [100];
	char sortStr [100];

	char temp [2];
	char ret [100];
	char charStr;

#ifdef _DEBUG_
	printf ("(D) dataLen : %d\n", strlen (data));
#endif

	memset (tmpStr, 0x00, sizeof (tmpStr));

	for (i = 0; i < (strlen (data)); i++)
	{
		if (data[i] != 32)
		{
			tmpStr [j] = data[i];
			++j;
		}
	}

#ifdef _DEBUG_
	for (i = 0; i < strlen (tmpStr); i++)
	{
		printf ("(D) tmpStr[%d] : %c\n", i, tmpStr[i]);
	}
#endif

	memset (sortStr, 0x00, sizeof (sortStr));

	if (!strncasecmp (tmpStr, "0x", 2))
	{
		for (i = 0; i < strlen (tmpStr); i += 4)
		{
			memset (buff, 0x00, sizeof (buff));
			sprintf (buff, "%c%c", tmpStr[i+2], tmpStr[i+3]);

			strcat (sortStr, buff);
		}
	}
	else
	{
		strcpy (sortStr, tmpStr);
	}

	len = strlen (sortStr);

#ifdef _DEBUG_
	for (i = 0; i < len; i++)
	{
		printf ("(D) sortStr[%d] : %c\n", i, sortStr[i]);
	}
#endif

	memset (ret, 0x00, sizeof (ret));

	for (i = 0; i < (len - 1); i = i + 2)
	{
		memset (temp, 0x00, sizeof (temp));

		temp[0] = sortStr[i];
		temp[1] = sortStr[i+1];

		for (j = 0; j < 2; j++)
		{
			if ((temp[j] >= 48) && (temp[j] <= 57))
			{
				temp[j] = temp[j] - 48;
			}
			else if ((temp[j] >= 97) && (temp[j] <= 102))
			{
				temp[j] = temp[j] - 87;
			}
			else if ((temp[j] >= 65) && (temp[j] <= 70))
			{
				temp[j] = temp[j] - 55;
			}
			else
			{
				printf ("%d thin put is not valid\n", 2 * i + j + 1);
				exit (0);
			}
		}

		temp[0] = temp[0]<<4;

		charStr = temp[0] | temp[1];

		//printf ("%c", charStr);

		ret [k] = charStr;
#ifdef _DEBUG_
		printf ("ret [%d] : %c\n", k, ret [k]);
#endif
		++k;

	}
#ifdef __DEBUG__
	printf ("Hex : %s -> Char : %s\n", data, ret);
#endif
	strcpy (result, ret);

	return result;
}

char *BinToDec (char *num, char *result)
{
	int i, j, k = 0;
	int len;
	int tmp;
	int chgRet = 0;

	char chgDec [100];
	char ret [100];

	memset (chgDec, 0x00, sizeof (chgDec));

	strcpy (chgDec, num);

	len = strlen (chgDec);
#ifdef _DEBUG_
	printf ("(D) len : %d\n", len);
#endif
	for (i = len - 1; i >= 0; i--)
	{
#ifdef _DEBUG_
		printf ("chgDec[%d] : %d\n", i, chgDec [i]);
#endif
		tmp = 0;

		tmp = chgDec [i] - 48;

		for (j = 0; j < k; j++)
		{
			tmp *= 2;
		}

		chgRet += tmp;

		++k;
	}

	memset (ret, 0x00, sizeof (ret));

	sprintf (ret, "%d", chgRet);
#ifdef __DEBUG__
	printf ("Bin : %s -> Dec : %s\n", num, ret);
#endif
	strcpy (result, ret);

	return result;
}

char *BinToHex (char *num, char *result)
{
	char *pRet;
	char chgNum [100];
	char ret [100];

	memset (chgNum, 0x00, sizeof (chgNum));

	strcpy (chgNum, BinToDec (num, chgNum));

	memset (ret, 0x00, sizeof (ret));

	strcpy (ret, DecToHex (chgNum, ret));

	strcpy (result, ret);

	return result;
}

char *BinToChar (char *num, char *result)
{
	int i;
	int j = 0;

	char *token = NULL;
	char *next = NULL;
	char buff [2];

	char tmpStr [100];
	char chgNum [100];
	char tRet [100];
	char ret [100];

	memset (tmpStr, 0x00, sizeof (tmpStr));

	strcpy (tmpStr, num);

	if ((token = strtok_r (tmpStr, " ", &next)) == NULL)
	{
		printf ("(E) Error... : %s\n", tmpStr);

		exit (0);
	}

	memset (chgNum, 0x00, sizeof (chgNum));

	while (token != NULL)
	{
#ifdef _DEBUG_
		printf ("(D) token : %s\n", token);
#endif
		memset (tRet, 0x00, sizeof (tRet));

		strcpy (tRet, BinToHex (token, tRet));

		strcat (chgNum, tRet);

		token = strtok_r (NULL, " ", &next);
	}
#ifdef _DEBUG_
	printf ("chgNum : %s\n", chgNum);
#endif

	memset (ret, 0x00, sizeof (ret));

	strcpy (ret, HexToChar (chgNum, ret));

#ifdef _DEBUG_
	printf ("(D) ret : %s\n", ret);
#endif
	strcpy (result, ret);

	return result;
}

char *CharToHex (char *data, char *result)
{
	int i;
	int j = 0;

	char temp [5];
	char tmpStr [100];
	char chgNum [100];

	memset (tmpStr, 0x00, sizeof (tmpStr));
	memset (chgNum, 0x00, sizeof (chgNum));

	for (i = 0; i < (strlen (data)); i++)
	{
		if (data[i] != 32)
		{
			tmpStr [j] = data[i];
			++j;
		}
	}

	for (i = 0; i < strlen (tmpStr); i++)
	{
		memset (temp, 0x00, sizeof (temp));

		sprintf (temp, "0x%.02x ", tmpStr [i]);
		strcat (chgNum, temp);
	}

	strcpy (result, chgNum);

	return result;
}

