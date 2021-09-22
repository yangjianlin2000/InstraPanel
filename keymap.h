#ifndef KEYMAP_H
#define KEYMAP_H


#define KEY_UP  'w'
#define KEY_DOWN  's'
#define KEY_LEFT 'a'
#define KEY_RIGHT 'd'
#define KEY_ENTER 'o'
#define KEY_ESC 'e'

#define KEY_PAGE_UP ','
#define KEY_PAGE_DOWN '.'

#define KEY_SDQD 'z'
#define KEY_CKQD 'x'
#define KEY_QDRC 'v'

#define KEY_MODE_CHANGE  'm'
#define KEY_TAP_POSITION 't'

typedef struct _KeyInfo
{
	uint16_t keyid;
	uint16_t data;
}KeyInfo;

union KeyEvent
{
	KeyInfo keyinfo;
	unsigned int keyval;
};





#endif // KEYMAP_H
