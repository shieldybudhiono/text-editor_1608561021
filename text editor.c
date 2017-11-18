#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
    char huruf;
    struct data *next,*prev;
}teks;

teks *head=NULL,*baru,*temp,*tail,*cetak;
teks *del,*after,*before=NULL;

void tambah()
{
    baru=(teks*)malloc(sizeof(teks));
    fflush(stdin);
    printf("ketik 1 karakter\t:");
    scanf("%c",&baru->huruf);
    baru->next=NULL;
    if (head==NULL)
    {
        head=baru;
        tail=baru;
        temp=baru;
        head->next=NULL;
        before=(teks*)malloc(sizeof(teks));
        head->prev=before;
        before->next=head;
        before->prev=NULL;
    }
    else if (temp->next==NULL)
    {
        temp->next=baru;
        tail=baru;
        tail->prev=temp;
        temp=baru;
    }
    else if (temp->prev==NULL)
    {
        head->prev=baru;
        before->next=baru;
        baru->prev=before;
        baru->next=head;
        head=baru;
        temp=head;
        before->prev=NULL;

    }
    else
    {
        after=temp->next;
        temp->next=baru;
        after->prev=baru;
        baru->next=after;
        baru->prev=temp;
        temp=baru;
    }
    printf("\n");
    system("pause");
}

void hapus()
{
    if(temp==before)
    {
        printf("\ntidak ada yang dihapus\n");
    }
    else if(head==tail)
    {
        del=head;
        temp=before;
        printf("\nkarakter %c sudah dihapus\n",del->huruf);
        free(del);
        head=NULL;
    }
    else if(temp->next==NULL)
    {
        tail=tail->prev;
        del=temp;
        temp=temp->prev;
        printf("\nkarakter %c sudah dihapus\n",del->huruf);
        free(del);
        tail->next=NULL;
    }
    else if(temp==head)
    {

        del=head;
        temp=before;
        head=head->next;
        printf("\nkarakter %c sudah dihapus\n",del->huruf);
        free(del);
        temp->next=head;
        head->prev=before;
    }
    else
    {
        del=temp;
        temp=temp->prev;
        del->next->prev=temp;
        temp->next=del->next;
        printf("\nkarakter %c sudah dihapus\n",del->huruf);
        free(del);
    }
    printf("\n");
    system("pause");
}

void left()
{
    if(temp==before)
    {
        printf("\npointer sudah paling kiri\n");
    }
    else
    {
        printf("\npointer telah digeser ke kiri\n");
        temp=temp->prev;
    }
    printf("\n");
    system("pause");
}

void right()
{
    if(temp==tail)
    {
        printf("\npointer sudah paling kanan\n");
    }
    else
    {
        printf("\npointer telah digeser ke kanan\n");
        temp=temp->next;
    }
    printf("\n");
    system("pause");
}

void print()
{
    if(head!=NULL)
    {
        cetak=head;
        while(cetak!=NULL)
        {
            printf("%c",cetak->huruf);
            cetak=cetak->next;
        }

    }
    else
    {
        printf("\n(kosong)\n");
    }
    printf("\n");
    system("pause");
}

int main()
{
    int a,i,pilih;
    fflush(stdin);
    system("cls");
    printf("\t\tProgram Mengetik\n");
    printf("Masukkan jumlah perintah:");
    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        system("cls");
        fflush(stdin);
        printf("ke-%d\nMenu\t:\n",i+1);
        printf("1.insert\n2.delete\n3.shift left\n4.shift right\n5.print\n");
        printf("pilih\t:");
        scanf("%d",&pilih);
        switch(pilih)
        {
            case 1:tambah();
            break;
            case 2:hapus();
            break;
            case 3:left();
            break;
            case 4:right();
            break;
            case 5: print();
            break;
            default : main();

        }
    }
    return 0;
}
