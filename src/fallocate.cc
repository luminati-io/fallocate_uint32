#include <nan.h>

using namespace v8;

NAN_METHOD(Fallocate)
{
    if (info.Length()<4)
    {
        Nan::ThrowTypeError("Wrong number of arguments");
        return;
    }
    if (!info[0]->IsNumber()||!info[1]->IsNumber()||!info[2]->IsNumber()||!info[3]->IsNumber())
    {
        Nan::ThrowTypeError("Wrong arguments");
        return;
    }
    Local<Context> ctx = Nan::GetCurrentContext();
    int fd = info[0]->Uint32Value(ctx).FromJust();
    int mode = info[1]->Uint32Value(ctx).FromJust();
    off_t offset = info[2]->Uint32Value(ctx).FromJust();
    off_t len = info[3]->NumberValue(ctx).FromJust();
    int retval = fallocate(fd, mode, offset, len);
    info.GetReturnValue().Set(retval);
}

NAN_MODULE_INIT(Init){
    Nan::Set(target, Nan::New("fallocate").ToLocalChecked(),
        Nan::GetFunction(Nan::New<FunctionTemplate>(Fallocate)).ToLocalChecked());
}

NODE_MODULE(fallocate, Init)
