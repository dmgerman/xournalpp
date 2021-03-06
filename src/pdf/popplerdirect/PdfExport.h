/*
 * Xournal++
 *
 * Handles PDF Export
 *
 * @author Xournal Team
 * http://xournal.sf.net
 *
 * @license GPL
 */

#ifndef __PDFEXPORT_H__
#define __PDFEXPORT_H__

#include "../../model/Document.h"
#include <String.h>
#include "../../control/jobs/ProgressListener.h"
#include "../cairo/CairoPdf.h"
#include "PdfXRef.h"
#include "PdfBookmark.h"
#include "PdfWriter.h"
#include "PdfRefList.h"
#include "PdfObjectWriter.h"
#include <glib.h>

class PdfExport
{
public:
	PdfExport(Document* doc, ProgressListener* progressListener);
	virtual ~PdfExport();

public:
	bool createPdf(String uri);
	bool createPdf(String uri, GList* range);
	String getLastError();

private:
	void addPopplerDocument(XojPopplerDocument doc);

	bool addPopplerPage(XojPopplerPage* pdf, XojPopplerDocument doc);
	bool writePage(int page);

	void writeGzStream(Stream* str, GList* replacementList);
	void writePlainStream(Stream* str, GList* replacementList);

	void writeStream(const char* str, int len, GList* replacementList);

	bool parseFooter();
	bool writeFooter();

	bool writePagesindex();
	bool writeCatalog();
	bool writeCrossRef();
	bool writeTrailer();
	bool writeResourcedict();
	bool writeResources();

private:
	XOJ_TYPE_ATTRIB;

	Document* doc;
	XojPopplerDocument currentPdfDoc;

	ProgressListener* progressListener;

	String lastError;

	int dataXrefStart;

	GList* pageIds;

	int outlineRoot;

	Dict* resources;

	GList* documents;

	GHashTable* refListsOther;

	PdfXRef* xref;
	PdfBookmarks bookmarks;
	PdfWriter* writer;
	PdfObjectWriter* objectWriter;

	CairoPdf cPdf;
};

#endif /* __PDFEXPORT_H__ */
