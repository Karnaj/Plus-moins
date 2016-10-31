#include <stdio.h>
#include <time.h>
#define MIN 1

double random(void);
int randint(const int a, const int b);
int getInt(void);
void viderBuffer(void);
int demanderMax(void);

int main(void)
{
	int nombre, test = 0, coups = 0, max;
	srand(time(NULL));
	puts("Le but de ce programme est de vous faire deviner un nombre.\n"
	     "Vous allez maintenant chosir la valeur maximale que pourra prendre ce nombre.");
	max = demanderMax();    
	nombre = tirerNombre(MIN, max);
	printf("Vous devez deviner un nombre entre 1 et %d.\n\n", max);
	while(nombre != test && ++coups)
	{
		printf("Donnez un nombre : ");
		test = getInt();
		if(test > nombre)
			puts("Le nombre est plus petit.\n");
		else if(test < nombre)
			puts("Le nombre est plus grand.\n");
	}
	printf("\nBravo, vous l'avez fait en %d essais !", coups);
	getchar();
	return 0;
}

int demanderMax(void)
{
	int niveau = -1, n = 10;
	while(niveau < 1 || niveau > 3)
	{
		puts("\n1. Le maximum est 10\n"
		     "2. Le maximum est 100\n"
		     "3. Le maximum est 1000\n");
		printf("Choisissez un niveau : ");
		niveau = getInt();
	}
	while(niveau != 1 && (n *= 10) && niveau--);
	return n;
}

int getInt(void)
{
	int nombre = -1;
	while(scanf("%d", &nombre) < 1)
		viderBuffer();
	viderBuffer();
	return nombre;
}

void viderBuffer(void)
{
	int c;
	while((c=getchar()) != EOF && c != '\n');
}

double random(void) 
{
	return (double) rand() / RAND_MAX;
}

int randint(const int a, const int b)
{
	return (int)(a + (b-a) * random());
}
