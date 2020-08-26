TWndMethod  _OldProc;
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{


	_OldProc = RzPanel2->WindowProc;
	RzPanel2->WindowProc = PanelWndProc;

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PanelWndProc(Messages::TMessage &Message)
{
 // 阻斷訊息
#if 1
	if(Message.Msg == WM_NCHITTEST){
		//const LRESULT result = ::DefWindowProc(this->Handle, WM_NCHITTEST, Message.WParam, Message.LParam);

		_OldProc(Message);
		//TPanel::WindowProc(Message);

		// Get the location of the mouse click, which is packed into lParam.
		POINT pt;
		pt.x = GET_X_LPARAM(Message.LParam);
		pt.y = GET_Y_LPARAM(Message.WParam);

		// You want to change HTCLIENT into HTCAPTION for a certain rectangle, rcDraggable.
		// Everything else should be left alone.
		 RECT rcDraggable;
		 rcDraggable.left = 0;
		 rcDraggable.top = 0;
		 rcDraggable.right = RzPanel2->Width;
		 rcDraggable.bottom = RzPanel2->Height;

		RECT rc = rcDraggable;
		MapWindowPoints(RzPanel2->Handle,   /* a handle to your window       */
										NULL,   /* convert to screen coordinates */
										reinterpret_cast<POINT*>(&rc),
										(sizeof(RECT) / sizeof(POINT)));

		if ((Message.Result == HTCLIENT)/* && (PtInRect(&rcDraggable, pt))*/)
		{
			Message.Result = HTCAPTION;
		}
		return;
	}
#endif
	// 繼續原始訊息的分派
	_OldProc(Message);
}