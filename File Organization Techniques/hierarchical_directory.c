//  Hierarchical Level Directory

#include <stdio.h>
#include <graphics.h>

struct tree_element 
{
    char name[20];
    int x, y, ftype, lx, rx, nc, level;
    struct tree_element *link[5];
};

typedef struct tree_element node;

void create(node **root, int lev, char *dname, int lx, int rx, int x) 
{
    int i, gap;
    if (*root == NULL) 
    {
        (*root) = (node *)malloc(sizeof(node));
        printf("Enter name of dir/file (under %s): ", dname);
        fflush(stdin);
        gets((*root)->name);
        printf("Enter 1 for Dir / 2 for file: ");
        scanf("%d", &(*root)->ftype);
        (*root)->level = lev;
        (*root)->y = 50 + lev * 50;
        (*root)->x = x;
        (*root)->lx = lx;
        (*root)->rx = rx;
        for (i = 0; i < 5; i++)
            (*root)->link[i] = NULL;

        if ((*root)->ftype == 1) 
        {
            printf("No of sub directories/files (for %s): ", (*root)->name);
            scanf("%d", &(*root)->nc);
            if ((*root)->nc == 0)
                gap = rx - lx;
            else
                gap = (rx - lx) / (*root)->nc;
            for (i = 0; i < (*root)->nc; i++)
                create(&((*root)->link[i]), lev + 1, (*root)->name, lx + gap * i, lx + gap * i + gap, lx + gap * i + gap / 2);
        } 
        else
            (*root)->nc = 0;
    }
}

void display(node *root) 
{
    int i;
    settextstyle(2, 0, 4);
    settextjustify(1, 1);
    setfillstyle(1, BLUE);
    setcolor(14);

    if (root != NULL) 
    {
        for (i = 0; i < root->nc; i++) 
        {
            line(root->x, root->y, root->link[i]->x, root->link[i]->y);
        }
        if (root->ftype == 1)
            bar3d(root->x - 20, root->y - 10, root->x + 20, root->y + 10, 0, 0);
        else
            fillellipse(root->x, root->y, 20, 20);
        outtextxy(root->x, root->y, root->name);

        for (i = 0; i < root->nc; i++) 
        {
            display(root->link[i]);
        }
    }
}

void main() 
{
    int gd = DETECT, gm;
    node *root = NULL;
    clrscr();
    create(&root, 0, "root", 0, 639, 320);
    clrscr();
    initgraph(&gd, &gm, "c:\\tc\\BGI");
    display(root);
    getch();
    closegraph();
}
