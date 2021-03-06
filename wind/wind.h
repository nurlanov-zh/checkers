#include <wx/wx.h>
#include <wx/socket.h>
#include <wx/valgen.h>
#include <wx/statusbr.h>

#define e 15
#define BLACK -1
#define WHITE 1
#define FREE 0			//************************
#define rad 12

struct Step{
	int green;	
	int who;
	int dead[4];	
	
};

class check20{
public:
	int a[20];  
	wxPoint pos[20];
	Step go[2];	
	int turn;
	int my_color;
	int ready;

	check20();
	int getNum(wxPoint);
	void stepClear();
	void stepPrep(int);
	bool ingreen(int);
	bool kill_opp();
	int win_check();
	void act(int);	
	


	class Iter{
		int* arr;
		int idx;

		public:

		Iter(int*);
		Iter* operator=(int);
		Iter* operator++(int);
		int operator[](int);
	};
};

// Класс, описывающий панель для рисования
class DrawPanel: public wxPanel{
  public:	
// в конструкторе указывается адрес объекта, который ее содержит

        DrawPanel(wxPanel *parent, wxStatusBar *sb, wxSocketClient *sc);
 // рисовалка
        void OnPaint(wxPaintEvent & event);
// составляющие цвета
	void OnDclick(wxMouseEvent& event); ///////////////////////////////////////////////
	check20 pl;
	wxStatusBar *dpsb;
	wxSocketClient *m_sc;
};

// Фрайм  который содержит панель, на которой две кнопки,
// и панель для рисования
class AddE: public wxFrame{   
	// Это наш клиентский сокет 
	wxSocketClient * m_SocketClient;
public:
	AddE(const wxString& title);
	~AddE(); 
	DECLARE_EVENT_TABLE()    
	
	wxPanel *m_pan; 		// панель для кнопок и планшета
	wxButton *bt, *ng; 		//, *bp; // кнопки смены цвета и закрытия
	DrawPanel *dp; 		 // панель для рисования
	
	wxMenuBar *menubar; 	// полоска для меню
	wxMenu *file; 		// менюшка  на полоске
	wxStatusBar *sb;		 // статус бар
	wxString ss;
	void OnQuit(wxCommandEvent& event);
	void OnNew(wxCommandEvent& event);
	
	// Обработчик событий от сокета
    void OnClientSocketEvent(wxSocketEvent & event);
    // Обработчик кнопки КОННЕКТ
    void OnConnect(wxCommandEvent & event);
    // Обработчик кнопки ДИСКОННЕКТ
    void OnDisconnect(wxCommandEvent & event);
};


class Pril: public wxApp{
    public:
        virtual bool OnInit();
};


