#include<iostream>
using namespace std;

struct tree{
    char label;
    tree *left, *right, *parent;
};

tree *root, *newNode;

void createDataAwalRoot(char label){
    if (root != NULL)
    {
        cout << "Data Tree sudah dibuat" << endl;
    } else
    {
        root = new tree();
        root -> label = label;
        root -> left = NULL;
        root -> right = NULL;
        root -> parent = NULL;
        cout << "\n" << label << "Berhasil dibuat menjadi root " << endl;
    }
}

tree *insertLeftData(char label, tree *root2){
    if (root == NULL)
    {
        cout << "Data root kosong, mohon isi terlebih dahulu" << endl;
        return NULL;
    } else
    {
        if (root2 -> left != NULL)
        {
            cout << "\nNode" << root2 -> label << "Sudah ada anak kiri" << endl;
            return NULL;
        } else
        {
            newNode = new tree();
            newNode -> label = label;
            newNode -> left = NULL;
            newNode -> right = NULL;
            newNode -> parent = root2;
            root2 -> left = newNode;
            cout << "\nNode " << label << " Berhasil ditambahkan untuk anak kiri " << newNode -> parent ->label << endl;
            return newNode;
        }
    } 
}

tree *insertRightData(char label, tree *root2){
    if (root == NULL)
    {
        cout << "Data root kosong, isi terlebih dahulu" << endl;
    } else
    {
        if (root2 -> right != NULL)
        {
            cout << "Node " << root2 -> label << " Sudah ada anak kanan" << endl;
            return NULL;
        } else
        {
            newNode = new tree();
            newNode -> label = label;
            newNode -> right = NULL;
            newNode -> left = NULL;
            newNode -> parent = root2;
            root2 -> right = newNode;
            cout << "\nNode " << label << " Berhasil ditambahkan untuk anak kanan " << newNode -> parent ->label << endl;
            return newNode;
        }
    }
}

bool cekIsiTree(){
    if (root == NULL)
    {
        cout << "Tree kosong" <<endl;
        return true;
    } else
    {
        cout << "Ada data tree" << endl;
        return false;
    }   
}

int main (){
    createDataAwalRoot('A');
    tree *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI, *nodeJ;

    nodeB = insertLeftData('B', root);
    nodeC = insertRightData('C', root);
    nodeD = insertLeftData('D', nodeB);
    nodeE = insertRightData('E', nodeB);
    nodeF = insertLeftData('F', nodeC);
    nodeG = insertLeftData('G', nodeE);
    nodeH = insertRightData('H', nodeE);
    nodeI = insertLeftData('I', nodeG);
    nodeJ = insertRightData('J', nodeG);

    cekIsiTree();
}