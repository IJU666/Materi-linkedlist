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

void update(char newLabel, tree *node){
    if (!root)
    {
        cout << "Buat tree terlebih dahulu" << endl;
    } else
    {
        if (!node)
        {
            cout << "Yang ingin dicari tidak ada" << endl;
        } else
        {
            char temp = node -> label;
            node -> label = newLabel;
            cout << "Label node " << temp << " Berhasil di ubah menjadi" << newLabel << endl;
        } 
    }
}

void retrieve(tree *node){
    cout << "Fungsi retrieve" << endl;
    if (!root)
    {
        cout << "\n Buat tree terlebih dahulu" << endl;
    } else
    {
        if (!node)
        {
            cout << "\n Node yang ditunjuk tidak ada" << endl;
        } else
        {
            cout << "Label Node : " << node -> label << endl;
        }
    }
}

void find(tree *node){
    if (!root)
    {
        cout << "\n Buat data tree terlebih dahulu" << endl;
    } else
    {
        if (!node)
        {
            cout << "\n Node yang ditunjuk tidak ada" << endl;
        } else
        {
            cout << "\nLabel Node : " << node -> label << endl;
            cout << "\nRoot Node : " << root -> label << endl;

            // cek parent
            if (node -> parent == NULL)
            {
                cout << "Tidak punya orang tua" << endl;
            } else
            {
                cout << "Parent Node : " << node -> parent -> label << endl;
            }  

            // cek sibling
            if (node -> parent != NULL && node -> parent -> left != node && node -> parent -> right == node)
            {
                cout << "\n Saudara kiri : " << node -> parent -> left -> label << endl;
            } else if (node -> parent != NULL && node -> parent -> right != node && node -> parent -> left == node)
            {
                cout << "\n Saudara Kanan : " << node -> parent -> right -> label << endl;
            } else
            {
                cout << "Tidak ada sodara" << endl;
            }
            
            //cek anak kiri
            if (node -> left == NULL)
            {
                cout << "Tidak mempunyai anak kiri" << endl;
            } else
            {
                cout << "Anak kiri node : " << node -> right -> label << endl;
            }
        } 
    }  
}

void preOrder(tree *node = root){
    if (root == NULL)
    {
        cout << "\n Buat tree terleboih dahulu" << endl;
    } else
    {
        if (node != NULL)
        {
            cout << node -> label << ",";
            preOrder(node-> left);
            preOrder(node-> right);
        }   
    }
}

void inOrder(tree *node = root){
    if (root == NULL)
    {
        cout << "\n Buat tree terleboih dahulu" << endl;
    } else
    {
        if (node != NULL)
        {
            inOrder(node-> left);
            cout << node -> label << ", ";
            inOrder(node-> right);
        }   
    }
}

void postOrder(tree *node = root){
    if (root == NULL)
    {
        cout << "\n Buat tree terleboih dahulu" << endl;
    } else
    {
        if (node != NULL)
        {
            postOrder(node-> left);
            postOrder(node-> right);
            cout << node -> label << ", ";
        }   
    }
}

void deleteTree(tree *node){
    if (root == NULL)
    {
        cout << "\n Buat tre terlebih dahulu" << endl;
    } else
    {
        if (node != NULL)
        {
            if (node != root)
            {
                node -> parent -> left = NULL;
                node -> parent -> right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
        }
        
        if (node == root)
        {
            delete root;
            root == NULL;
        } else
        {
            delete node;
        }
    }
}

void deleteSub(tree *node){
    if (root == NULL)
    {
        cout << "\n Buat tree terlebih dahulu" << endl;
    } else
    {
        deleteTree(node -> left);
        deleteTree(node -> right);
        cout << "Subtree dari node " << node -> label << " berhasil dihapus" << endl;
    }  
}

void clear(){
    if (root == NULL)
    {
        cout << "\nBuat Tree terlebih dahulu" << endl;
    } else
    {
        deleteTree(root);
        cout << "\nTree berhasil dihapus" << endl;
    }
}

int size(tree *node = root){
    if (!root)
    {
        cout << "\nBuat tree terlebih dahulu" << endl;
    } else
    {
        if (!node)
        {
            return 0;
        } else
        {
            return 1 + size(node -> left) + size(node -> right);
        }
    }
}

int height(tree *node = root){
    if (!root)
    {
        cout << "\nBuat tree terlebih dahulu" << endl;
    } else
    {
        if (!node)
        {
            return 0;
        } else
        {
            int heightKiri = height(node -> left);
            int heightKanan = height(node -> right);
            // bandingkan nilai heightkanan dan kiri
            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            } else
            {
                return heightKanan + 1;
            }  
        }
    }   
}

void karakteristik(){
    cout << "\nSize of tree : " << size() << endl;
    cout << "Height : " << height() << endl;
    cout << "Average of tree" << size()/height() << endl;
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