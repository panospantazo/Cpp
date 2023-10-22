#include <iostream>
#include <string>
#define size 100
using namespace std;



class video
{
    public:
        video();
        video(string, string, int);
        int get_vid_time() const;
       friend ostream & operator<<(ostream &, video &);
    private:
        string singers_name;
        string song_name;
        int vid_time;
};


class playlist
{
    public:
        playlist(string ,string ,int );
        void add_video(video&);
    

        friend ostream & operator<<(ostream &, playlist &);
    protected:
        string name;
        string description;
        int time;
        video arr[size];
        int arr_space;
};

class classical_playlist : public playlist
{
    public:
        classical_playlist(string, string ,int , string );
        friend ostream & operator<<(ostream &, classical_playlist &);
    private:
        string period;
};

ostream & operator<<(ostream &left, video &obj);
ostream & operator<<(ostream &left, playlist &obj);
ostream & operator<<(ostream &, classical_playlist &);

int main(void)
{
    classical_playlist opera("wow","yperteleio",0,"palaiolithikis");
    video palama("palamas","palamari",88);
    opera.add_video(palama);
    video sakala("sakalas","sakalamakalaka",55);
    opera.add_video(sakala);
    cout << opera;
    return 0;
}



ostream & operator<<(ostream &left, video &obj)
{
    left << "Song name: " << obj.song_name << endl;
    left << "Singer's name: " << obj.singers_name << endl;
    left << "Time duration: " << obj.vid_time << endl;

    return left;
}

ostream & operator<<(ostream &left, playlist &obj)
{
    int i;
    
    left << "Playlist Name: " << obj.name << "| Duration: " << obj.time << "| Description: " << obj.description << endl;
    left <<"-------------------------------------------------------" << endl;

    for(i = 0; i< obj.arr_space ;i++)
    {
        left << obj.arr[i] << endl;
    }
    return left;
}

video::video()
{
    singers_name = " ";
    song_name = " ";
    vid_time = 0;
}

video::video(string in_singers_name,string in_song_name,int inp_vid_time)
{
    singers_name = in_singers_name;
    song_name = in_song_name;
    vid_time = inp_vid_time;
}



int video::get_vid_time() const
{
    return vid_time;
}


playlist::playlist(string in_name,string in_description,int in_time)
{
    int i;

    name = in_name;
    description = in_description;
    time = in_time;
    arr_space = 0;
}

void playlist::add_video(video &in_vid)
{
    arr[arr_space] = in_vid;
    arr_space++;

    time += in_vid.get_vid_time();
}

classical_playlist::classical_playlist(string in_name,string in_description,int in_time, string in_period ):
playlist(in_name,in_description,in_time)
{
    period = in_period;
}

ostream & operator<<(ostream &left, classical_playlist &obj)
{
	int i;
    
    left << "Playlist Name: " << obj.name << "| Duration: " << obj.time << "| Description: " << obj.description << endl;
    left <<"-------------------------------------------------------" << endl;

    for(i = 0; i< obj.arr_space ;i++)
    {
        left << obj.arr[i] << endl;
    }
    return left;	
}

