#pragma once
#include <Windows.h>
#include "resource.h"
#include "convert.h"
#include "dbx_filtros.h"
#include "ctrl_dbx_acercade.h"
//#include "ejemplos.h"
#include "mod.picture.h"
//mod_picture picMenu;



LRESULT CALLBACK call_menu(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_INITDIALOG:
	{
		/*
		HWND hPicMenu = GetDlgItem(hWnd, PIC_FONDO);
		
		picMenu.setSize(1500, 480);
		picMenu.setPathDefault("config\\fondo.bmp");
		picMenu.id = PIC_FONDO;
		

		picMenu.setImagen((HBITMAP)LoadImage(NULL, convertCharArrayToLPCWSTR(picMenu.getPath()), IMAGE_BITMAP, picMenu.getSizeWidth(), picMenu.getSizeHeight(), LR_LOADFROMFILE));
		SendDlgItemMessage(hWnd, picMenu.id, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)picMenu.getImagen());
		*/

	}
	break;
	case WM_CLOSE:
		exit(0);
	break;
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
			case BTN_FILTROS:
				DialogBox(dbx_filtrado.hInst, MAKEINTRESOURCE(DBX_FILTROS), 0, reinterpret_cast<DLGPROC>(call_filtrado));
			break;
			case BTN_CONTEO:
				DialogBox(dbx_conteo.hInst, MAKEINTRESOURCE(DBX_CONTEO), 0, reinterpret_cast<DLGPROC>(call_conteo));
			break;
			case BTN_ACERCADE:
				DialogBox(dbx_acercade.hInst, MAKEINTRESOURCE(DBX_ACERCADE), 0, reinterpret_cast<DLGPROC>(call_acercade));
			break;


			case BTN_SALIR:
				exit(0);
			break;
			/*
			case WM_CLOSE:
				MessageBox(0, L"", L"", 0);
			break;*/
		}
	}
	break;
	}
	return false;
}