#include<iostream>
using namespace std;

struct circular
{
    string nama, pekerjaan;
    int umur;

    circular *next;
};

circular *head, *tail, *del, *newNode, *cur;

void createSingleCircular(string data[2], int umur){
    head = new circular();
    head -> nama = data[0];
    head -> pekerjaan = data[1];
    head -> umur = umur;
    tail = head;
    tail -> next = head;
}

void addFirst(string data[2], int umur){
    newNode = new circular();
    newNode -> nama = data[0];
    newNode -> pekerjaan = data[1];
    newNode -> umur = umur;
    newNode -> next = head;
    tail ->next = newNode; 
    tail = newNode;
}

void addLast(string data[2], int umur){
    newNode = new circular();
    newNode -> nama = data[0];
    newNode -> pekerjaan = data[1];
    newNode -> umur = umur;
    newNode -> next = head;
    tail ->next = newNode;
    tail = newNode; 
}

void removeFirst(){
    del = head;
    head = head -> next;
    tail -> next = head;
    delete del;
}

void removeLast(){
    del = tail;
    cur = head;
    while (cur->next != tail)
    {
        cur = cur -> next;
    }
    tail = cur;
    tail->next = head;
    delete del;
}

void printCircular(){
    cout << "---------------------------------------------------------------" << endl;
    cout << endl;
    cout << "| NAMA\t\t| ALAMAT\t\t| PEKERJAAN\t\t|" << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << endl;
    cur = head;
    while (cur -> next != head)
    {
        cout <<"| " << cur->nama << "\t| " << cur->umur << "\t| " << cur->pekerjaan << "\t\t| " << endl; 
        cur = cur ->next;
    }   
        cout <<"| " << cur->nama << "\t| " << cur->umur << "\t| " << cur->pekerjaan << "\t\t| " << endl; 
        cout << "---------------------------------------------------------------" << endl;
}
    

    string data[2];
    int umur;
int pertanyaan(){
    cout << "Masukan Nama Anda : "; cin >> data[0];
    cout << "Masukan Umur Anda : "; cin >> umur; cin.ignore();
    cout << "Masukan Pekerjaan Anda : "; cin >> data[1];
    return data, umur;
}

void menu(){
    cout << "1. Tambah data awal" << endl;
    cout << "2. Tambah data tengah" << endl;
    cout << "3. Tambah data akhir" << endl;
    cout << "4. Tampilkan Node" << endl;
    cout << "5. Hapus data awal" << endl;
    cout << "6. Hapus data akhir" << endl;
    cout << "0. keluar" << endl;
}

int main(){
    int pilihan;
 pertanyaan();  
 createSingleCircular(data,umur); 
do
{
    menu();
    cout << "Masukan nomor menu : "; cin >> pilihan;
    switch (pilihan)
    {
    case 1:
        pertanyaan();
        addFirst(data, umur);
        break;
    case 2:
    
    break;

    case 3:
    pertanyaan();
    addLast(data, umur);
    break;

    case 4:
    printCircular();
    break;

    case 5:
    removeFirst();
    cout << "data awal telah terhapus" << endl;
    break;

    case 6:
    removeLast();
    cout << "Data terakhir telah terhapus" << endl;
    break;
    
    default:
    cout << "Pilihan tidak ada" << endl;
        break;
    }
} while (pilihan != 0);

}