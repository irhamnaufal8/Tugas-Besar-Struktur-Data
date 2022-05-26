//
//  tubes.cpp
//  TUBES
//
//  Created by Garry on 26/12/21.
//

#include "tubes.hpp"

void create_list(mll &L){
    first(L) = nil;
}

void insert_parent(mll &list_mahasiswa, adr_mahasiswa m){
    if (first(list_mahasiswa) == nil) {
        first(list_mahasiswa) = m ;
    } else {
        adr_mahasiswa x = first(list_mahasiswa);
        while (next(x)!= nil){
            x = next(x);
        }
        next(x)= m;
    }
}

void menambahkan_mahasiswa(mll &list_mahasiswa){
    mahasiswa input;
    adr_mahasiswa m;
    cout << "Masukan Nama mahasiswa : ";
    cin >> input.nama;
    cout << "Masukan nim mahasiswa : ";
    cin >> input.nim;
    
    m = new_elm_mahasiswa(input);
    insert_parent(list_mahasiswa, m);
};

void delete_after_parent(mll &list_mahasiswa, adr_mahasiswa prec, adr_mahasiswa &m) {
    m = next(prec);
    next(prec) = next(m);
    next(m) = nil;
}

void delete_first_parent(mll &list_mahasiswa, adr_mahasiswa &m) {
    if (first(list_mahasiswa) == nil) {
        cout << "List Kosong" << endl;
    } else {
        m = first(list_mahasiswa);
        first(list_mahasiswa) = next(m);
        next(m) = nil;
    }
}

void delete_last_parent(mll &list_mahasiswa, adr_mahasiswa &m) {
    adr_mahasiswa p = first(list_mahasiswa);
    while (next(p) != nil) {
        p = next(p);
    }
    m = next(p);
}

void delete_parent(mll &list_mahasiswa){
    mahasiswa input;
    adr_mahasiswa m;
    cout << "Masukan Nama mahasiswa : ";
    cin >> input.nama;
    cout << "Masukan nim mahasiswa : ";
    cin >> input.nim;
    
    m = find_parent(list_mahasiswa, input);
    if(m == nil) {
        cout << "Tidak ada mahasiswa bernama tersebut" << endl;
    }else{
        adr_mahasiswa tmp = first(list_mahasiswa);
        while(tmp != nil && info(tmp).nama != info(m).nama && info(tmp).nim != info(tmp).nim ){
            tmp = next(tmp);
        };
        if (m == first(list_mahasiswa)){
            delete_first_parent(list_mahasiswa, m);
        } else if (next(tmp) == nil){
            delete_last_parent(list_mahasiswa, tmp);
        } else{
            adr_mahasiswa prec = first(list_mahasiswa);
            if (next(prec) != m) {
                prec = next(prec);
            }
            delete_after_parent(list_mahasiswa,prec, m);
        }
    }
}

void show_parent(mll list_mahasiswa) {
    if (first(list_mahasiswa) == nil) {
        cout << "- - - - - - - - Tidak Ada Data mahasiswa - - - - - - - -" << endl;
    } else {
        adr_mahasiswa m = first(list_mahasiswa);
        while (m != nil) {
            cout << "Nama   : " << info(m).nama << endl;
            cout << "nim    : " << info(m).nim;
            cout << endl << endl;
            m = next(m);
        }
    };
    cout << endl;
}

adr_mahasiswa find_parent(mll &list_mahasiswa, mahasiswa input){
    adr_mahasiswa x = first(list_mahasiswa);
    
    while (x != nil){
        if (info(x).nama == input.nama && info(x).nim == input.nim){
            return x;
        };
        x = next(x);
    }
    return nil;
}

void insert_child_of_parent(mll &list_mahasiswa) {
    mahasiswa input;
    prestasi n;
    adr_mahasiswa m;
    adr_prestasi p;
    adr_prestasi tmp;
    cout << "Masukan Nama Mahasiswa : ";
    cin >> input.nama;
    cout << "Masukan NIM : ";
    cin >> input.nim;
    m = find_parent(list_mahasiswa,input);
    if(m != nil){
        cout << "Masukan Nama Prestasi : ";
        cin >> n.prestasi;
        cout << "Juara ke : ";
        cin >> n.juara;
        p = find_child_of_parent(list_mahasiswa,n);
        if(p == nil){
            tmp = new_elm_prestasi(n);
            if (nextprestasi(m) == nil){
                nextprestasi(m) = tmp;
            } else{
                adr_prestasi x = nextprestasi(m);
                while (next(x) != nil){
                    x = next(x);
                }
                next(x) = tmp;
            };
        } else {
            cout<<"Prestasi Sudah Ada di Dalam List" << endl;
        }
    } else {
        cout<<"Mahasiswa Tidak Ditemukan" << endl;
    }
};

void delete_child_of_parent(mll &list_mahasiswa){
    adr_prestasi p;
    adr_mahasiswa m;
    mahasiswa input;
    prestasi n;
    cout <<"Masukan Nama mahasiswa : ";
    cin >> input.nama;
    cout << "Masukan nim mahasiswa : ";
    cin >> input.nim;
    m = find_parent(list_mahasiswa, input);
    if (m != nil) {
        cout<<"Masukkan Nama prestasi : ";
        cin >> n.prestasi;
        cout << "Masukkan juara Ke : ";
        cin >> n.juara;
        p = find_child_of_parent(list_mahasiswa, n);
        
        if (p != nil) {
            adr_prestasi q = nextprestasi(m);
            while (q != nil && info(q).prestasi != info(p).prestasi && info(q).juara != info(p).juara) {
                q = next(q);
            }
            if (nextprestasi(m) == p){
                delete_first_child(list_mahasiswa,p,m);
            } else if (next(q) == nil) {
                delete_last_child(list_mahasiswa,p,m);
            } else {
                adr_prestasi tmp = nextprestasi(m);
                while (next(tmp) != p){
                    tmp = next(tmp);
                };
                delete_after_child(list_mahasiswa,tmp,p,m);
            }
        }else {
            cout << "prestasi Tidak Ditemukan" <<endl;
        }
    } else {
        cout << "mahasiswa Tidak Ditemukan" << endl;
    }
}

void show_child_of_parent(mll list_mahasiswa){
    adr_mahasiswa m;
    adr_prestasi p;
    m = first(list_mahasiswa);
    while(m != nil) {
        cout << "Nama mahasiswa : ";
        cout << info(m).nama << endl;
        cout<<"NIM mahasiswa : ";
        cout<<info(m).nim<<endl;
        p = nextprestasi(m);
        if (p == nil){
            cout<<"Tidak Ada Prestasi!";
        } else {
            while(p != nil){
                cout<<"prestasi : ";
                cout<<info(p).prestasi<<endl;
                cout<<"juara Ke-";
                cout<<info(p).juara<<endl<< endl;
                
                p = next(p);
            }
        }
        m = next(m);
        cout << endl << endl;
    }
}
adr_prestasi new_elm_prestasi(prestasi x){
    adr_prestasi p;
    p = new elm_prestasi;
    info(p).prestasi = x.prestasi;
    info(p).juara = x.juara;
    next(p) =nil;
    
    return p;
}

void delete_last_child(mll &list_mahasiswa, adr_prestasi &p, adr_mahasiswa m){
    adr_prestasi x = nextprestasi(m);
    while(next(x) != nil){
        x = next(x);
    }
    p = next(x);
    next(x) = nil;
}



void delete_after_child(mll &list_mahasiswa, adr_prestasi prec, adr_prestasi &p, adr_mahasiswa m) {
    next(prec) = next(p);
    next(p) = nil;
}

void delete_first_child(mll &list_mahasiswa, adr_prestasi p, adr_mahasiswa m) {
    adr_prestasi x = nextprestasi(m);
    if(next(x) == nil) {
        nextprestasi(m) = nil;
    } else {
        nextprestasi(m) = next(p);
        next(p) = nil;
    }
}

void delete_last_child(mll &list_mahasiswa, adr_prestasi p, adr_mahasiswa m) {
    adr_prestasi x = nextprestasi(m);
    while(next(x) != nil) {
        x = next(x);
    }
    p = next(x);
    next(x) = nil;
}

adr_prestasi find_child_of_parent(mll &list_mahasiswa, prestasi input) {
    adr_mahasiswa m = first(list_mahasiswa);
    adr_prestasi p;
    
    while (m != nil) {
        p = nextprestasi(m);
        while (p != nil) {
            if(info(p).prestasi == input.prestasi && info(p).juara == input.juara) {
                return p;
            }
            p = next(p);
        }
        m = next(m);
    }
    return 0;
}

adr_mahasiswa new_elm_mahasiswa(mahasiswa x) {
    adr_mahasiswa m;
    m = new elm_mahasiswa;
    info(m).nama = x.nama;
    info(m).nim = x.nim;
    next(m) = nil;
    nextprestasi(m) = nil;
    
    return m;
}

void delate_relation(mll &list_mahasiswa) {
    mahasiswa m;
    adr_mahasiswa tmp;
    
    cout << "Masukan Nama mahasiswa :";
    cin >> m.nama;
    cout << "Masukan nim mahasiswa :";
    cin >> m.nim;
    tmp = find_parent(list_mahasiswa, m);
    if (tmp != nil){
        nextprestasi(tmp) = nil;
    } else {
        cout << "Nama Tidak Ditemukan" << endl;
    }
}


void update_some(mll &list_mahasiswa) {
    cout << "- - Prestasi Yang Ingin Diubah - -" << endl;
    delete_child_of_parent(list_mahasiswa);
    cout << endl << "- - - Prestasi Baru - - -" << endl;
    insert_child_of_parent(list_mahasiswa);
    cout << endl;
    
}

void count_prestasi(mll &list_mahasiswa) {
    int i = 0;
    mahasiswa input;
    adr_mahasiswa m;
    
    cout << "Masukkan Nama mahasiswa: ";
    cin >> input.nama;
    cout << "Masukkan nim mahasiswa: ";
    cin >> input.nim;
    
    m = find_parent(list_mahasiswa, input);
    
    if (m != nil) {
        adr_prestasi p = nextprestasi(m);
        while (p != nil) {
            i = i + 1;
            p = next(p);
        }
        cout << "Jumlah prestasi " << info(m).nama << ": " << i << endl;
    } else {
        cout << "Nama mahasiswa Tidak Ditemukan!" << endl;
    }
}

int selectmenu() {
    cout << "- - - - - - - - Menu - - - - - - - -" << endl;
    cout << "1. Menambahkan mahasiswa" << endl;
    cout << "2. Menampilkan Data mahasiswa" << endl;
    cout << "3. Menghapuskan Data mahasiswa" << endl;
    cout << "4. Menambahkan Data Prestasi Mahasiswa" << endl;
    cout << "5. Menampilkan prestasi mahasiswa" << endl;
    cout << "6. Menghapus prestasi mahasiswa" << endl;
    cout << "7. Menghapus Relasi" << endl;
    cout << "8. Mengubah prestasi" << endl;
    cout << "9. Menghitung Jumlah prestasi mahasiswa" << endl;
    cout << "0. EXIT" << endl;
    cout << "- - - - - - - - - - - - - - - - - -" << endl;
    cout << "Pilihan Menu: ";
    
    int input = 0;
    cin >> input;
    cout << endl;
    
    return input;
}
