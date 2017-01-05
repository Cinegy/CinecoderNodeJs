class C_CinecoderErrorHandler : public ICC_ErrorHandler
{
   STDMETHOD(QueryInterface)(REFIID riid, void**p)
   {
     if(p == NULL)
       return E_POINTER;

     *p = NULL;

     if(riid != IID_ICC_ErrorHandler && riid != IID_IUnknown)
       return E_NOINTERFACE;

     *p = static_cast<ICC_ErrorHandler*>(this);

     return S_OK;
   }
   STDMETHOD_(ULONG,AddRef)()
   {
     return 2;
   }
   STDMETHOD_(ULONG,Release)()
   {
     return 1;
   }
   STDMETHOD(ErrorHandlerFunc)(HRESULT ErrCode, LPCSTR ErrDescription, LPCSTR pFileName, INT LineNo)
   {
     fprintf(stderr, "Error %08xh (%s) at %s(%d): %s\n", ErrCode, Cinecoder_GetErrorString(ErrCode), pFileName, LineNo, ErrDescription);
     exit(ErrCode);
     return 0;
   }
};
