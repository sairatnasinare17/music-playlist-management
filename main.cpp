#include <iostream>
#include <string>
using namespace std;

struct Song
{
    string name;
    Song *prev;
    Song *next;
};

class Playlist
{
    Song *head;
    Song *current;

public:

    Playlist()
    {
        head = NULL;
        current = NULL;
    }

    void addSong()
    {
        Song *newSong = new Song;

        cout << "Enter song name: ";
        getline(cin, newSong->name);

        newSong->prev = NULL;
        newSong->next = NULL;

        if (head == NULL)
        {
            head = newSong;
            current = newSong;
        }
        else
        {
            Song *temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newSong;
            newSong->prev = temp;
        }

        cout << "Song added successfully!\n";
    }

    void deleteSong()
    {
        string name;

        cout << "Enter song name to delete: ";
        getline(cin, name);

        Song *temp = head;

        while (temp != NULL && temp->name != name)
            temp = temp->next;

        if (temp == NULL)
        {
            cout << "Song not found!\n";
            return;
        }

        if (temp == head)
        {
            head = temp->next;

            if (head != NULL)
                head->prev = NULL;
        }
        else
        {
            temp->prev->next = temp->next;

            if (temp->next != NULL)
                temp->next->prev = temp->prev;
        }

        if (current == temp)
            current = head;

        delete temp;

        cout << "Song deleted successfully!\n";
    }

    void searchSong()
    {
        string name;

        cout << "Enter song name to search: ";
        getline(cin, name);

        Song *temp = head;

        while (temp != NULL)
        {
            if (temp->name == name)
            {
                cout << "Song found!\n";
                return;
            }

            temp = temp->next;
        }

        cout << "Song not found!\n";
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "Playlist is empty!\n";
            return;
        }

        Song *temp = head;

        cout << "\nPlaylist:\n";

        while (temp != NULL)
        {
            cout << temp->name << endl;
            temp = temp->next;
        }
    }

    void nextSong()
    {
        if (current == NULL)
        {
            cout << "Playlist is empty!\n";
        }
        else if (current->next == NULL)
        {
            cout << "Already at last song!\n";
        }
        else
        {
            current = current->next;
            cout << "Playing: " << current->name << endl;
        }
    }

    void previousSong()
    {
        if (current == NULL)
        {
            cout << "Playlist is empty!\n";
        }
        else if (current->prev == NULL)
        {
            cout << "Already at first song!\n";
        }
        else
        {
            current = current->prev;
            cout << "Playing: " << current->name << endl;
        }
    }
};

int main()
{
    Playlist p;
    int choice;

    do
    {
        cout << "\n--- MUSIC PLAYLIST ---\n";
        cout << "1. Add Song\n";
        cout << "2. Delete Song\n";
        cout << "3. Search Song\n";
        cout << "4. Display Playlist\n";
        cout << "5. Next Song\n";
        cout << "6. Previous Song\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1:
                p.addSong();
                break;

            case 2:
                p.deleteSong();
                break;

            case 3:
                p.searchSong();
                break;

            case 4:
                p.display();
                break;

            case 5:
                p.nextSong();
                break;

            case 6:
                p.previousSong();
                break;

            case 7:
                cout << "Program ended.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 7);

    return 0;
}