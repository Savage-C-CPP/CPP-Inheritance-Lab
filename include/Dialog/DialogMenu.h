#ifndef __DIALOG_MENU_H__
#define __DIALOG_MENU_H__

typedef void (*Delegate)(void);

struct MenuEntry
{
    char choice;
    char const *title;
    bool blocked;
    Delegate procedure;
};

#endif //__DIALOG_MENU_H__
