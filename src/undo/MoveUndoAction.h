/*
 * Xournal++
 *
 * Undo move action (EditSelection)
 *
 * @author Xournal Team
 * http://xournal.sf.net
 *
 * @license GPL
 */

#ifndef __RELMOVEUNDOACTION_H__
#define __RELMOVEUNDOACTION_H__

#include "UndoAction.h"
#include <glib.h>

class XojPage;
class Layer;
class Redrawable;

class MoveUndoAction: public UndoAction
{
public:
	MoveUndoAction(Layer* sourceLayer, PageRef sourcePage,
	                  GList* selected, double mx, double my,
	                  Layer* targetLayer, PageRef targetPage);
	virtual ~MoveUndoAction();

public:
	virtual bool undo(Control* control);
	virtual bool redo(Control* control);
	XojPage** getPages();
	virtual String getText();

private:
	void switchLayer(GList* entries, Layer* oldLayer, Layer* newLayer);
	void repaint();
	void move();

private:
	XOJ_TYPE_ATTRIB;

	GList* elements;
	PageRef targetPage;

	Layer* sourceLayer;
	Layer* targetLayer;

	String text;

	double dx, dy;
};

#endif /* __RELMOVEUNDOACTION_H__ */
