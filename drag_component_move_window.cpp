//---------------------------------------------------------------------------
void __fastcall TMainForm::RzPanel2MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	ReleaseCapture();
	this->Perform(WM_SYSCOMMAND,SC_SIZE | 9, 0);
}
//---------------------------------------------------------------------------