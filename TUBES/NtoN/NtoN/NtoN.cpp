//
//  NtoN.cpp
//  NtoN
//
//  Created by Garry on 31/12/21.
//

#include "NtoN.hpp"

void createList(Listmahasiswa &L) {
    first(L) = nil;
    last(L) = nil;
}

adr_mahasiswa createelmmahasiswa(string nama_mahasiswa, string nim) {
    adr_mahasiswa D;
    D = new elmmahasiswa;
    info(D).nama_mahasiswa = nama_mahasiswa;
    info(D).nim = nim;
    next(D) = nil;
    prev(D) = nil;
    nextprestasi(D) = nil;
    return D;
}

adr_prestasi createelmprestasi(string prestasi, int juara) {
    adr_prestasi P;
    P = new elmprestasi;
    info(P).prestasi = prestasi;
    info(P).juara = juara;
    next(P) = nil;
    return P;
}

void insertmahasiswa(Listmahasiswa &L, adr_mahasiswa D) {
    if(first(L) == nil) {
        first(L) = D;
        last(L) = D;
    } else {
        next(last(L)) = D;
        prev(D) = last(L);
        last(L) = D;
    }
}
void menambahkan_mahasiswa(Listmahasiswa &L){
    parent input;
    adr_mahasiswa D;
    cout << "Masukan Nama mahasiswa : ";
    cin >> input.nama_mahasiswa;
    cout << "Masukan nim mahasiswa : ";
    cin >> input.nim;

    D = createelmmahasiswa(input.nama_mahasiswa, input.nim);
    insertmahasiswa(L, D);
};

void insertprestasi(Listmahasiswa &L, adr_mahasiswa D, adr_prestasi P) {
    adr_prestasi temp;
    if(D != nil) {
        temp = nextprestasi(D);
        if(temp != nil) {
            while(next(temp) != nil) {
                temp = next(temp);
            }
            next(temp) = P;
        } else {
            nextprestasi(D) = P;
        }
    } else {
        cout<<"mahasiswa Tidak Ditemukan!"<<endl<<endl;
    }
}

void menambahkan_prestasi(Listmahasiswa &L){
    adr_mahasiswa D;
    adr_prestasi P;
    child n;
    parent input;

    cout << "Masukan Nama mahasiswa : ";
    cin >> input.nama_mahasiswa;
    cout << "Masukan nim mahasiswa : ";
    cin >> input.nim;
    D = findmahasiswa(L, input.nim);
    if (D != nil){
        cout << "Masukkan Nama prestasi: ";
        cin >> n.prestasi;
        cout << "Masukkan juara Ke: ";
        cin >> n.juara;
        P = createelmprestasi(n.prestasi, n.juara);
        insertprestasi(L, D, P);
    } else {
        cout<<"Nama mahasiswa tidak ditemukan"<<endl;
    }
    
};

adr_mahasiswa findmahasiswa(Listmahasiswa L, string nim) {
    adr_mahasiswa D;
    D = first(L);
    while(D != nil) {
        if(info(D).nim == nim) {
            return D;
        } else {
            D = next(D);
        }
    }
    return nil;
}

adr_prestasi findprestasi(Listmahasiswa L, string prestasi, string nim) {
    adr_mahasiswa D;
    adr_prestasi P;
    D = findmahasiswa(L, nim);
    if(D != nil) {
        P = nextprestasi(D);
        while(P != nil) {
            if(info(P).prestasi == prestasi) {
                return P;
            } else {
                P = next(P);
            }
        }
    }
    return nil;
}

void deletemahasiswa(Listmahasiswa &L, adr_mahasiswa D ) {
    if(D != nil) {
        if(D == first(L)) {
            deleteFirstmahasiswa(L, D);
        } else if(D == last(L)) {
            deleteLastmahasiswa(L, D);
        } else {
            deleteAftermahasiswa(L, D);
        }
        cout<<"mahasiswa Telah Dihapus!"<<endl;
    } else {
        cout<<"mahasiswa Tidak Ditemukan!"<<endl;
    }
    cout<<endl;
}
void delete_parent(Listmahasiswa &L){
    parent input;
    adr_mahasiswa D;
    cout << "Masukan Nama mahasiswa : ";
    cin >> input.nama_mahasiswa;
    cout << "Masukan nim mahasiswa : ";
    cin >> input.nim;

    D = findmahasiswa(L, input.nim);
    deletemahasiswa(L, D);
}
void deleteprestasi(Listmahasiswa &L, string prestasi, string nim) {
    adr_mahasiswa D;
    adr_prestasi P;
    D = findmahasiswa(L, nim);
    if(D != nil) {
        P = findprestasi(L, prestasi, nim);
        if(P != nil) {
            if(P == nextprestasi(D)) {
                deleteFirstprestasi(D, P);
            } else if(next(P) == nil) {
                deleteLastprestasi(D, P);
            } else {
                deleteAfterprestasi(D, P);
            }
            cout<<"prestasi Berhasil Dihapus!"<<endl;
        } else {
            cout<<"prestasi Tidak Ditemukan!"<<endl;
        }
    } else {
        cout<<"mahasiswa Tidak Ditemukan!"<<endl;
    }
    cout<<endl;
}

void menghapusprestasi(Listmahasiswa &L){
    adr_prestasi P;
    adr_mahasiswa D;
    parent input;
    child n;
    cout <<"Masukan Nama mahasiswa : ";
    cin >> input.nama_mahasiswa;
    cout << "Masukan nim mahasiswa : ";
    cin >> input.nim;
    D = findmahasiswa(L, input.nim);
    if (D != nil) {
        cout<<"Masukkan Nama prestasi : ";
        cin >> n.prestasi;
        cout << "Masukkan juara Ke : ";
        cin >> n.juara;
        P = findprestasi(L, n.prestasi, input.nim);
    } else {
        cout << "mahasiswa Tidak Ditemukan" << endl;
    }
    deleteprestasi(L, n.prestasi, input.nim);

}
void deleteFirstprestasi(adr_mahasiswa &D, adr_prestasi &P) {
    if(next(P) == nil) {
        nextprestasi(D) = nil;
    } else {
        nextprestasi(D) = next(P);
        next(P) = nil;
    }
}

void deleteLastprestasi(adr_mahasiswa &D, adr_prestasi &P) {
    adr_prestasi temp;
    temp = nextprestasi(D);
    while(next(temp) != P) {
        temp = next(temp);
    }
    next(temp) = nil;
}

void deleteAfterprestasi(adr_mahasiswa &D, adr_prestasi &P) {
    adr_prestasi temp;
    temp = nextprestasi(D);
    while(next(temp) != P) {
        temp = next(temp);
    }
    next(temp) = next(P);
    next(P) = nil;
}

void deleteFirstmahasiswa(Listmahasiswa &L, adr_mahasiswa D) {
    if(next(D) == nil) {
        first(L) = nil;
        last(L) = nil;
    } else {
        first(L) = next(D);
        next(D) = nil;
        prev(first(L)) = nil;
    }
}

void deleteLastmahasiswa(Listmahasiswa &L, adr_mahasiswa D) {
    last(L) = prev(D);
    prev(D) = nil;
    next(last(L)) = nil;
}

void deleteAftermahasiswa(Listmahasiswa &L, adr_mahasiswa D) {
    adr_mahasiswa temp;
    temp = prev(D);
    next(temp) = next(D);
    prev(next(temp)) = temp;
    next(D) = nil;
    prev(D) = nil;
}

void showmahasiswa(Listmahasiswa L) {
    adr_mahasiswa D;
    D = first(L);
    cout<<"List mahasiswa!"<<endl;
    if(first(L) != nil) {
        while(D != nil) {
            cout<<"Nama mahasiswa: "<<info(D).nama_mahasiswa<<endl;
            cout<<"nim mahasiswa: "<<info(D).nim<<endl;
            cout<<endl;
            D = next(D);
        }
    } else {
        cout<<"List Kosong!"<<endl;
    }
    cout<<endl;
}

void showprestasi(Listmahasiswa L) {
    adr_mahasiswa D;
    adr_prestasi P;
    string nim;
    
    cout << "Masukkan nim : "; cin >> nim;
    
    D = findmahasiswa(L, nim);
    cout<<"List prestasi mahasiswa!"<<endl;
    if(D != nil) {
        cout<<"Nama mahasiswa: " << info(D).nama_mahasiswa << endl;
        cout<<"nim mahasiswa: " << info(D).nim << endl;
        P = nextprestasi(D);
        if(P == nil) {
            cout<<"Tidak Ada prestasi!"<<endl;
        } else {
            while(P != nil) {
                cout<<"Nama prestasi: " << info(P).prestasi << endl;
                cout<<"juara Ke-" << info(P).juara << endl;
                P = next(P);
            }
        }
    } else {
        cout<<"mahasiswa Tidak Ditemukan!"<<endl;
    }
    cout<<endl;
}

void delate_relation(Listmahasiswa L) {
    parent m;
    adr_mahasiswa tmp;
    
    cout << "Masukan Nama mahasiswa :";
    cin >> m.nama_mahasiswa;
    cout << "Masukan nim mahasiswa :";
    cin >> m.nim;
    tmp = findmahasiswa(L, m.nim);
    if (tmp != nil){
        nextprestasi(tmp) = nil;
    } else {
        cout << "Nama Tidak Ditemukan" << endl;
    }
}

void update_some(Listmahasiswa L) {
    cout << "- - Prestasi Yang Ingin Diubah - -" << endl;
    menghapusprestasi(L);
    cout << endl << "- - - Prestasi Baru - - -" << endl;
    menambahkan_prestasi(L);
    cout << endl;
}

void count_matakuliah(Listmahasiswa L) {
    int i = 0;
    parent input;
    adr_mahasiswa m;
    
    cout << "Masukkan Nama mahasiswa: ";
    cin >> input.nama_mahasiswa;
    cout << "Masukkan nim mahasiswa: ";
    cin >> input.nim;
    
    m = findmahasiswa(L, input.nim);
    
    if (m != nil) {
        adr_prestasi p = nextprestasi(m);
        while (p != nil) {
            i = i + 1;
            p = next(p);
        }
        cout << "Jumlah prestasi " << info(m).nama_mahasiswa << ": " << i << endl;
    } else {
        cout << "Nama mahasiswa Tidak Ditemukan!" << endl;
    }
}

int selectmenu() {
    cout << "- - - - - - - - Menu - - - - - - - -" << endl;
    cout << "1. Menambahkan mahasiswa" << endl;
    cout << "2. Menampilkan Data mahasiswa" << endl;
    cout << "3. Menghapuskan Data mahasiswa" << endl;
    cout << "4. Menambahkan Data prestasi" << endl;
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
