#include<iostream>
using namespace std;

struct mahasiswa
{
    string nama, jurusan, semester, namaDosen, ruangan;
    int sks, waktu = 50;

    mahasiswa *prev, *next;
};

mahasiswa *head, *tail, *newNode, *del, *cur, *afterNode;

void createFirstData(string nama, string jurusan, int semester){
    head = new mahasiswa();
    head -> nama = nama;
    head -> jurusan = jurusan;
    head -> semester = semester;
    head -> prev = head;
    head -> next = head;
    tail = head;
}

void addFirst(string nama, string jurusan, int semester){
    if (head == NULL)
    {
        cout << "Data awal kosong" << endl;
    } else
    {
        newNode = new mahasiswa();
        newNode -> nama = nama;
        newNode -> jurusan = jurusan;
        newNode -> semester = semester;
        newNode -> prev = tail;
        newNode -> next = head;
        head -> prev = newNode;
        tail -> next = newNode;
        head = newNode;
    }    
}

void addMiddle(string nama, string jurusan, int semester, int posisi){
    if (head == NULL)
    {
        cout << "Data awal kosong" << endl;
    } else
    {
        if (posisi == 1)
        {
            cout << "Posisi yang anda mau adalah bukan posisi tengah" <<endl;
        }else if (posisi < 1)
        {
            cout << "posisi diluar jangkauan" << endl;
        }else
        {
        newNode = new mahasiswa();
        newNode -> nama = nama;
        newNode -> jurusan = jurusan;
        newNode -> semester = semester;

        // transversing 
        int nomor = 1;
        cur = head;
        while (nomor  < posisi -1)
        {
            cur = cur -> next;
            nomor++;
        }
        afterNode = cur -> next;
        cur -> next = newNode;
        afterNode -> prev = newNode;
        newNode -> prev = cur;
        newNode -> next = afterNode;
        }
    }
    
    
    
    
    
}

void addLast(string nama, string jurusan, int semester){
    if (head == NULL)
    {
    cout << "Data awal kosong" <<endl;
    } else
    {
     newNode = new mahasiswa();
    newNode -> nama = nama;
    newNode -> jurusan = jurusan;
    newNode -> semester = semester;
    newNode -> prev = tail;
    newNode -> next = head;
    head -> prev = newNode;
    tail -> next = newNode;
    tail = newNode;
    }
}

void removeFirst(){
    if (head == NULL)
    {
        cout << "Data awal kosong" <<endl;
    } else
    {
        del = head;
        head = head -> next;
        tail -> next = head;
        head -> prev = tail;
        delete del;
    }
}

void removeMiddle(int posisi){
    // pengecekan data
    if (head == NULL)
    {
        cout << "Data awal kosong" << endl;
    } else
    {
        /* code */
     if (posisi == 1)
    {
        cout << "Posisi yang anda mau adalah bukan posisi tengah" <<endl;
    }else if (posisi < 1)
    {
        cout << "posisi diluar jangkauan" << endl;
    }else
    {
    // transversing 
    int nomor = 1;
    cur = head;
    while (nomor  < posisi -1)
    {
        cur = cur -> next;
        nomor++;
    }
    del = cur -> next;
    afterNode = del -> next;
    cur -> next = afterNode;
    afterNode -> prev = cur;
    delete del;
    }
    }
    
    
    
}

void removeLast(){
    if (head == NULL)
    {
        cout << "Data awal kosong" << endl;
    } else
    {
    del = tail;
    tail = tail -> prev;
    tail -> next = head;
    head -> prev = tail;
    delete del;
    }
    
    
}


void tampil(){

    if (head == NULL)
    {
        cout << "Data kosong" << endl;
    } else
    {
        cur = head;
        while (cur -> next != head)
    {
        cout << "Nama Mahasiswa : " << cur -> nama << endl;
        cout << "Jurusan Mahasiswa : " << cur -> jurusan << endl;
        cout << "Semester Mahasiswa : " << cur -> semester << endl;
        cout << endl;
        cur = cur -> next;

    }
        cout << "Nama Mahasiswa : " << cur -> nama << endl;
        cout << "Jurusan Mahasiswa : " << cur -> jurusan << endl;
        cout << "Semester Mahasiswa : " << cur -> semester << endl;
    }
}


string nama, jurusan;
int semester;
int pertanyaan(){
    cout << "Masukan nama Mahasiswa : "; cin >> nama;
    cout << "Masukan jurusan Mahasiswa : "; cin >> jurusan;
    cout << "Masukan semester Mahasiswa : "; cin >> semester;
    return nama, jurusan, semester;
}

void menu(){
    cout << "1. Tambah data awal" << endl;
    cout << "2. Tambah data tengah" << endl;
    cout << "3. Tambah data akhir" << endl;
    cout << "4. Tampilkan Node" << endl;
    cout << "5. Hapus data awal" << endl;
    cout << "6. Hapus data tengah" << endl;
    cout << "7. Hapus data akhir" << endl;
    cout << "0. keluar" << endl;
}

int main(){
    int pilihan, posisi;
    cout << "\t DATA MAHASISWA" << endl;
    pertanyaan();
    createFirstData(nama, jurusan, semester);  
    do
    {
        menu();
            cout << "Masukan pilihan anda : "; cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            pertanyaan();
            addFirst(nama, jurusan, semester);
        break;

        case 2:
            pertanyaan();
            cout << "Masukan posisi : "; cin >> posisi;
            addMiddle(nama, jurusan, semester, posisi);
        break;
        
        case 3:
            pertanyaan();
            addLast(nama, jurusan, semester);
        break;

        case 4:
            tampil();
        break;

        case 5:
            removeFirst();
            cout << "Data awal telah terhapus" << endl;
        break;

        case 6:
            cout << "Masukan posisi yang ingin dihapus : "; cin >> posisi;
            removeMiddle(posisi);
            cout << "Data tengah telah terhapus" << endl;
        break;

        case 7:
            removeLast();
            cout << "Data terakhir telah terhapus" << endl;
        break;


        default:
        cout << "Pilihan tidak ada" << endl;
            break;
        }
    } while (pilihan != 0);
    

}