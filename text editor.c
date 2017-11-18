#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
    char kota[100],nama[20];
    int berat;
    int id;
    struct data *next,*prev;
}barang;

int i,n=0,ID,r=0,x;
char y;
barang *head,*tail,*themp;

void header()
{
    system("cls");
    fflush(stdin);
    printf("\t\t*********************************\n");
    printf("\t\tPROGRAM ANTRIAN PENGIRIMAN BARANG\n");
    printf("\t\t*********************************\n\n");
}

void tambah()
{
        system("cls");
        header();
        themp = (barang *) malloc(sizeof(barang));
        themp->id = r+1;
        printf("ID code : %d\n", themp->id);
        printf("Nama barang : ");
        fflush(stdin);
        gets(themp->nama);
        printf("Berat barang : ");
        scanf("%d",&themp->berat);
        printf("Kota tujuan pegiriman : ");
        fflush(stdin);
        gets(themp->kota);
        themp->next=NULL;
    if (n==0)
    {
        head=themp;
        tail=themp;
    }
    else
    {
        tail->next = themp;
        themp->prev = tail;
        tail=themp;
    }
    r++;
    n++;
    printf("\nApakah anda ingin menambah data lagi ? Y/T : ");
    fflush(stdin);
    scanf("%c", &y);
    if(y == 'y' || y == 'Y')
    {
        tambah();
    }
    else
    {
        main();
    }
}
void hapus()
{
    header();
    system("cls");
    if (n==0)
    {
        printf("\n\nData Kosong\n\n");
    }
    else
    {
        printf("ID yang ingin dihapus : ");
        scanf("%d", &ID);
        themp=head;
        while(themp->next != NULL)
        {
            if(themp->id == ID)
            {
                x=1;
                break;
            }
            themp=themp->next;
        }
        if(x==0)
        {
            printf("Data tidak ditemukan\n\n");
           system("pause");
            main();
        }
        else
        {
            printf("ID code: %d\n", themp->id);
            printf("Nama barang: %s\n", themp->nama);
            printf("Berat barang : %d\n", themp->berat);
            printf("Kota tujuan pegiriman: %s\n", themp->kota);

            if(themp==head && themp==tail)
            {
                free(themp);
            }
            else if(themp==head)
            {
                head=head->next;
                free(themp);
                head->prev=NULL;
            }
            else if(themp==tail)
            {
                tail=tail->prev;
                themp=tail->next;
                free(themp);
                tail->next = NULL;
            }
            else
            {
                themp->prev->next=themp->next;
                themp->next->prev = themp->prev;
                free(themp);
            }
        }
            n--;
            printf("\n\nData Berhasil di hapus");
            printf("\n\nApakah anda ingin menghapus data lagi ? Y/T : ");
            fflush(stdin);
            scanf("%c", &y);
            if(y == 'y' || y == 'Y')
            {
                hapus();
            }
            else
            {
                main();
            }
    }
                 system("pause");
}

void tampil()
{
    themp=head;
    system("cls");
    header();
    printf("No\t\tNama barang\t\tBerat barang\tKota tujuan pengiriman\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t\t%s\t\t\t%d\t\t%s\n",themp->id, themp->nama,themp->berat,themp->kota);
        themp=themp->next;
    }
   system("pause");
    main();
}

void edit()
{
    printf("Cari ID : ");
    scanf("%d", &ID);
    x=0;
    themp=head;
    for(i=0;i<n;i++)
    {
        if(ID == themp->id)
        {
            x=1;
        }
        else
        {
            themp=themp->next;
        }
    }

    if(x==0)
    {
        printf("\nData tidak ada\n\n");
        system("pause");
        main();
    }
    else
    {
        themp->id = ID;
        printf("ID code: %d\n", themp->id);
        printf("Nama barang: %s\n", themp->nama);
        printf("Berat barang : %d\n", themp->berat);
        printf("Kota tujuan pegiriman: %s\n", themp->kota);
        printf("Ganti data diatas ? Y/T : ");
        fflush(stdin);
        scanf("%c", &y);
        if(y=='y' || y=='Y')
        {
            printf("Nama barang : ");
            fflush(stdin);
            gets(themp->nama);
            printf("Berat barang : ");
            scanf("%d",&themp->berat);
            printf("Kota tujuan pegiriman : ");
            fflush(stdin);
            gets(themp->kota);
            r=1;
        }
        else
        {
            main();
        }
    }
}

int main()
{
   int pil;
    menu: system("cls");
    header();
    printf("Menu : \n");
    printf("1. Tambah data\n2. Edit data\n3. Hapus data\n4. Tampil data\n5. Keluar\n\n");
    printf("Pilihan : ");
    scanf("%d", &pil);
    switch(pil)
    {
        case 1 : tambah(); break;
        case 2 : edit(); break;
        case 3 : hapus(); break;
        case 4 : tampil(); break;
        case 5 : printf("Apakah Anda ingin keluar ? Y/T : ");
                 fflush(stdin);
                 scanf("%c", &y);
                 if(y=='y' || y == 'Y')
                    return 0;
                 else main();
        default: main();
    }
    getch();
    return 0;

