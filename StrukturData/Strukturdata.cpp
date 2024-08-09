#include <stdio.h>
#include <string.h>

// Mendefinisikan struktur Mahasiswa
struct Mahasiswa {
    char npm[15];
    char nama[50];
    char tempat_lahir[30];
    char tanggal_lahir[15];
    char prodi[50];
};

// Fungsi untuk menambah data mahasiswa
void tambahMahasiswa(struct Mahasiswa *m, char *npm, char *nama, char *tempat_lahir, char *tanggal_lahir, char *prodi) {
    strcpy(m->npm, npm);
    strcpy(m->nama, nama);
    strcpy(m->tempat_lahir, tempat_lahir);
    strcpy(m->tanggal_lahir, tanggal_lahir);
    strcpy(m->prodi, prodi);
}

// Fungsi untuk menampilkan data mahasiswa
void tampilMahasiswa(struct Mahasiswa m) {
    printf("NPM: %s\n", m.npm);
    printf("Nama: %s\n", m.nama);
    printf("Tempat Lahir: %s\n", m.tempat_lahir);
    printf("Tanggal Lahir: %s\n", m.tanggal_lahir);
    printf("Prodi: %s\n\n", m.prodi);
}

// Fungsi untuk menghapus data mahasiswa
void hapusMahasiswa(struct Mahasiswa *m) {
    strcpy(m->npm, "");
    strcpy(m->nama, "");
    strcpy(m->tempat_lahir, "");
    strcpy(m->tanggal_lahir, "");
    strcpy(m->prodi, "");
}

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    printf("Menu:\n");
    printf("1. Tambah Data Mahasiswa\n");
    printf("2. Hapus Data Mahasiswa\n");
    printf("3. Tampilkan Data Mahasiswa\n");
    printf("4. Keluar\n");
    printf("Pilih opsi (1-4): ");
}

int main() {
    struct Mahasiswa mhs;
    int pilihan;
    char npm[15], nama[50], tempat_lahir[30], tanggal_lahir[15], prodi[50];

    do {
        tampilkanMenu();
        scanf("%d", &pilihan);

        switch(pilihan) {
            case 1:
                // Tambah Data Mahasiswa
                printf("Masukkan NPM: ");
                scanf("%s", npm);
                printf("Masukkan Nama: ");
                scanf(" %[^\n]%*c", nama);  // Input string dengan spasi
                printf("Masukkan Tempat Lahir: ");
                scanf(" %[^\n]%*c", tempat_lahir);
                printf("Masukkan Tanggal Lahir (dd-mm-yyyy): ");
                scanf("%s", tanggal_lahir);
                printf("Masukkan Prodi: ");
                scanf(" %[^\n]%*c", prodi);

                tambahMahasiswa(&mhs, npm, nama, tempat_lahir, tanggal_lahir, prodi);
                printf("Data mahasiswa berhasil ditambahkan!\n");
                break;

            case 2:
                // Hapus Data Mahasiswa
                hapusMahasiswa(&mhs);
                printf("Data mahasiswa berhasil dihapus!\n");
                break;

            case 3:
                // Tampilkan Data Mahasiswa
                printf("Data Mahasiswa:\n");
                tampilMahasiswa(mhs);
                break;

            case 4:
                // Keluar
                printf("Keluar dari program.\n");
                break;

            default:
                printf("Pilihan tidak valid! Silakan coba lagi.\n");
                break;
        }

    } while(pilihan != 4);

    return 0;
}
