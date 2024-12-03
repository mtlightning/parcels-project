
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>
    float alanFonksiyonu(int arr[100], int len)
    {
        int birim = 10;
        int alan;
        int toplamsol = 0;
        int toplamsag = 0;
      
        
        for (int i = 0; i < len - 3; i += 2)
        {
            toplamsol += (arr[i] * arr[i + 3]) / (birim * birim);
        }
        for (int i = 0; i < len - 3; i += 2)
        {
            toplamsag += (arr[i + 1] * arr[i + 2]) / (birim * birim);
        }
        (alan) = (abs(toplamsol - toplamsag)) / 2;
		return alan;
    }

   int main()

    {
    	
    	system("curl http://abilgisayar.kocaeli.edu.tr/prolab1/prolab1.txt -o prolab1.txt");
    	
    	     FILE *dosya;
    dosya = fopen("prolab1.txt", "r");



    if (dosya == NULL)
    {
        printf("Dosya acilamadi");
        exit(0);
    }
    char karakter;
    int sayilar[100];
    int sayilar_2[100] = {NULL};
    int sayilar_1[100] = {NULL};
    int sayilar_3[100] = {NULL};
    int sayac = 0;
    char sayi[10];
    int satir;
    int satir_sayisi=0;
    int byte_boyut = 0;
    int sekil_sayisi = 0;
    int tutucu = 0;
    int kontrol = 0;
    int j = 0;
    int k = 0;
    int p = 0;
    int yer;
    int yer2;
    int birim = 10;
    int rezervMiktari;
    printf("lutfen kacinci satiri yazdirmak istediginizi giriniz :");
    scanf("%d", &satir);



		// dosyanin i�indeki veriyi istenilen sat�ra g�re atlan�cak dosya boyutunu belirliyor
            while ((karakter = fgetc(dosya)) != EOF)
        {
            byte_boyut++;
            

           if (karakter == 'F')
           {
            
            satir_sayisi++;
           }
            if(satir_sayisi+1==satir)
        {
        	break;
		}
        }
        if(satir_sayisi>9)
        {
        	byte_boyut++;
		}
       fseek(dosya, byte_boyut+2, SEEK_SET);
        while ((karakter = fgetc(dosya)) != EOF)
        {

            if (isdigit(karakter))
            {
                // Say�lar� karakter dizisi olarak okuyor ve diziye ekliyor
                int sayisira = 0;
                sayi[sayisira++] = karakter;

                while (isdigit(karakter = fgetc(dosya)))
                {
                    sayi[sayisira++] = karakter;
                }

                sayi[sayisira] = '\0';
                sayilar[sayac] = atoi(sayi);
                sayac++;
            }

            if (karakter == 'F')
            {
                break;
            }
       }
    
		// sat�rdaki farkl� �ekilleri ay�rmak i�in �ekillerin ba�lang�� indexlerini bulan kod 
        for (int g = 2; g < sayac; g += 2)
        {

            if (sayilar[g] == sayilar[tutucu] && sayilar[g + 1] == sayilar[tutucu + 1])
            {
                sekil_sayisi++;
                tutucu = g + 2;
                g += 4;
                kontrol++;
                if (kontrol == 1)
                {
                    yer = tutucu;
                }
                if (kontrol==2)
                {
                    yer2=tutucu;
                }
                
            }
        }
        fclose(dosya);
        //  say�lar dizisindeki farkl� �ekilleri ay�rarak her bir �ekli farkl� diziye at�yopr ve bu dizilerin uzunlugunu buluyor
        int sayac1=0,sayac2=0,sayac3=0;
        for (int g = 0; g < sayac; g++)
        {

            printf(" %d ", sayilar[g]);
            if (g >= yer && g<yer2)
            {

                sayilar_2[j] = sayilar[g];
                j++;
                sayac2++;
            }
            if (g>=yer2)
            {
                sayilar_3[p]=sayilar[g];
                p++;
                sayac3++;
            }
            
            if (g<yer)
            {
                
                sayilar_1[k] = sayilar[g];
                k++;
                sayac1++;
            
            }
            
            
        }
        printf("\nsekil sayisi :%d\n", sekil_sayisi);
        //ayr� dizilerdeki �ekillerin bast�rma i�lemi

        printf("\n1. sekil :"); 
        for (int g = 0; g < k; g++)
        {
            printf(" %d ", sayilar_1[g]);
        }

        printf("\n2. sekil :");
        for (int g = 0; g < j; g++)
        {
            printf(" %d ", sayilar_2[g]);
        }
        printf("\n3. sekil :");
        for (int g = 0; g < p; g++)
        {
            printf(" %d ", sayilar_3[g]);
        }
        int arabalar=1;
        int birimPlatformMaliyeti;
        int birimSondajMaaliyeti;
        printf("\nBirim sondaj maaliyeti icin bir deger giriniz (1-10):");
        while(arabalar)
        {
        scanf("%d", &birimSondajMaaliyeti);
        if(birimSondajMaaliyeti<=10 && birimSondajMaaliyeti>=1)
		{
			break;
			}
			printf("Lutfen belirtilen araliklarda bir sayi giriniz:");	
		}
		
        printf("Birim platform maliyetini giriniz:");
        while(arabalar)
        {
        scanf("%d", &birimPlatformMaliyeti);        	
        if(birimPlatformMaliyeti>0)
		{
			break;
			}	
			printf("Lutfen pozitif bir deger giriniz:");	
			
		}
        // txt dosyas�ndan �ekti�imiz verileri fonksiyona g�nderece�imiz diziye atama i�lemi
        

        for (int i = 0; i < sayac; i++)
        {
            sayilar_1[i] = birim * sayilar_1[i];
        }
        printf("\n");

		for (int i = 0; i < sayac; i++)
        {
           
            sayilar_2[i] = birim * sayilar_2[i];
        }
        for (int i = 0; i < sayac; i++)
        {
         
            sayilar_3[i] = birim * sayilar_3[i];
        }
        printf("\n");
        
        
        
		
        
        

        // �izdirme i�lemi

        int window1;
        window1 = initwindow(1500, 1500, "Pencere 1");
       int toplam;
        for(int i=1;i<=sekil_sayisi;i++)
        {
        	if(i==1)
		{
	
		setfillstyle(1, 6);
        fillpoly(sayac1/2, sayilar_1);
        alanFonksiyonu(sayilar_1, sayac);
        
		}
	
		if(i==2)
		{
		setfillstyle(1, 6);
        fillpoly(sayac2/2,sayilar_2);                             
        alanFonksiyonu(sayilar_2, sayac);
		}
		if(i==3)
		{
	
		setfillstyle(1, 6);
        fillpoly(sayac3/2, sayilar_3);
        alanFonksiyonu(sayilar_3, sayac);
        
		}
		}
	int AlanlarinToplami=alanFonksiyonu(sayilar_1, sayac)+alanFonksiyonu(sayilar_2, sayac)+alanFonksiyonu(sayilar_3, sayac);
	rezervMiktari=(AlanlarinToplami*10);
	printf("Toplam Alan=%d\n",AlanlarinToplami);
	printf("Rezerv Miktari=%d",rezervMiktari);	
	
        
        // Birim kareleri �izdiren kod
        for (int i=0;i<1500/birim;i++)
        {
            line(i*birim,0,i*birim,1500);
        }
        for (int i=0;i<1500/birim;i++)
        {
            line(0,i*birim,1500,i*birim);
        }
       
		
       
         getch();
        closegraph(); // Grafik�ekran�n��kapat
        
        
        
        
        // 2.pencereyi a�an k�s�m
         int window2;
          window2=initwindow(1500, 1500, "Pencere 2");
          
       
        
        for(int i=1;i<=sekil_sayisi;i++)
        {
        	if(i==1)
		{
	
		setfillstyle(1, BLUE);
        fillpoly(sayac1/2, sayilar_1);
        
        
		}
	
		if(i==2)
		{
		setfillstyle(1, BLUE);
        fillpoly(sayac2/2,sayilar_2);
       
		}
		if(i==3)
		{
	
		setfillstyle(1, BLUE);
        fillpoly(sayac3/2, sayilar_3);
        
        
		}
		}
		
		k=0;
		j=0;
		p=0;
		setcolor(BLACK);
		 for (int i = 0; i < 1500 / birim; i++)
        {line(i * birim, 0, i * birim, 1500);
        	if(sayilar_1[k]<=i)
        	{ 
        		i++;
			}
			if(sayilar_2[j]<=i)
        	{ 
        		i++;
			}
			if(sayilar_3[p]<=i)
        	{ 
        		i++;
			}
        	
            
            k++;
            j++;
            p++;
            
        }
        k=0;
		j=0;
		p=0;
		// �ekillerin i�ini birim karelere b�len kod
		setlinestyle(0,0,3);
        for (int i = 0; i < 1500 / birim; i++)
        {
		line(i * birim, 0, i * birim, 1500);
        		if(sayilar_1[k+1]<=i)
        	{
        		
        		i++;
			}
			if(sayilar_2[j+1]<=i)
        	{
        	
        		i++;
			}
			if(sayilar_3[p+1]<=i)
        	{
        		
        		i++;
			}
			
			
	   
            k+=1;
            j+=2;
            p+=1;
            line(0, i * birim, 1500, i * birim);
            setfillstyle(2,BLUE);
        }

		
        getch();
        closegraph(); // Grafik�ekran�n��kapat
       
    }

