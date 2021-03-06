/*
 * TextDrawer.h
 *
 *  Created on: 31-okt-2010
 *      Author: Stefan
 */

#ifndef TEXTDRAWER_H_
#define TEXTDRAWER_H_

class cTextDrawer {
	public:
		cTextDrawer();
		cTextDrawer(ALFONT_FONT *theFont);
		~cTextDrawer();
		void drawTextWithOneInteger(int x, int y, const char * msg, int var);
		void drawTextWithTwoIntegers(int x, int y, const char * msg, int var1, int var2);
		void drawText(int x, int y, const char * msg);
		void drawText(int x, int y, const char * msg, int color);

		void drawTextCentered(const char * msg, int y);
		void drawTextCentered(const char * msg, int y, int color);

		void drawTextBottomRight(const char * msg);
		void drawTextBottomLeft(const char * msg);

		void setApplyShaddow(bool value) { applyShadow = value; }

	protected:

	private:
		ALFONT_FONT *font;
		bool applyShadow;

};

#endif /* TEXTDRAWER_H_ */
