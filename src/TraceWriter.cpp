#include <TraceWriter.h>

CTraceWriter::CTraceWriter(const string& filename, ios_base::openmode mode)
{
    tracer_.open(filename, mode);
    if(tracer_.good())
        return;
    cout << "cannot open file " << filename << endl;
}

bool CTraceWriter::open(const string& filename, ios_base::openmode mode)
{
    tracer_.open(filename, mode);
    return tracer_.good();
}

template <typename T>
bool CTraceWriter::write(T&& elem)
{
    if(!tracer_.is_open())
    {
        cout << "file is not open!" << endl;
        return false;
    }
    tracer_ << elem;
    return true;
}
template <typename T, typename ... Ts>
bool CTraceWriter::write(T&& t, Ts&& ... ts)
{
    write(forward<T>(t));
    return write(forward<Ts>(ts)...);
}

int main()
{
    CTraceWriter trc("pippo.txt", std::ofstream::out);
    array<double, 2> arr{1.2, 2.3};
    trc.write("pippo", 2);
    return 0;
}
