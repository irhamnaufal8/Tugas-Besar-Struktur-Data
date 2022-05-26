//
//  NtoN.hpp
//  NtoN
//
//  Created by Garry on 31/12/21.
//

#ifndef NtoN_hpp
#define NtoN_hpp
#include <iostream>

using namespace std;

#define first(L) ((L).first)
#define last(L) ((L).last)
#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define nextprestasi(P) (P)->nextprestasi
#define input(P) ((P).input)
#define nil NULL

struct parent {
    string nama_mahasiswa, nim;
};

struct child {
    string prestasi;
    int juara;
};

typedef struct elmmahasiswa *adr_mahasiswa;
typedef struct elmprestasi *adr_prestasi;

struct elmmahasiswa {
    parent info;
    adr_mahasiswa next;
    adr_mahasiswa prev;
    adr_prestasi nextprestasi;
};

struct elmprestasi {
    child info;
    adr_prestasi next;
};

struct Listmahasiswa {
    adr_mahasiswa first;
    adr_mahasiswa last;
};

void createList(Listmahasiswa &L);

adr_mahasiswa createelmmahasiswa(string nama_mahasiswa, string nim);
adr_prestasi createelmprestasi(string prestasi, int juara);

void insertmahasiswa(Listmahasiswa &L, adr_mahasiswa D);
void menambahkan_mahasiswa(Listmahasiswa &L);
void insertprestasi(Listmahasiswa &L, adr_mahasiswa D, adr_prestasi P);
void menambahkan_prestasi(Listmahasiswa &L);

adr_mahasiswa findmahasiswa(Listmahasiswa L, string nim);
adr_prestasi findprestasi(Listmahasiswa L, string prestasi, string nim);

void deletemahasiswa(Listmahasiswa &L, string nim);
void delete_parent(Listmahasiswa &L);
void deleteprestasi(Listmahasiswa &L, string prestasi, string nim);
void menghapusprestasi(Listmahasiswa &L);

void deleteFirstprestasi(adr_mahasiswa &D, adr_prestasi &P);
void deleteLastprestasi(adr_mahasiswa &D, adr_prestasi &P);
void deleteAfterprestasi(adr_mahasiswa &D, adr_prestasi &P);

void deleteFirstmahasiswa(Listmahasiswa &L, adr_mahasiswa D);
void deleteLastmahasiswa(Listmahasiswa &L, adr_mahasiswa D);
void deleteAftermahasiswa(Listmahasiswa &L, adr_mahasiswa D);

void showmahasiswa(Listmahasiswa L);
void showprestasi(Listmahasiswa L);

void delate_relation(Listmahasiswa L);
void update_some(Listmahasiswa L);
void count_matakuliah(Listmahasiswa L);


int selectmenu();

#endif /* NtoN_hpp */
