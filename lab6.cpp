#include <iostream>
#include <map>
#include <vector>

using namespace std;

class IGate
{
    public:
        virtual int evaluate()  = 0;
        virtual void print() const = 0;
        virtual ~IGate() = default;

};

class Gate : IGate
{
private:
    map<int, int> &m_nodes;
public:
    Gate(map<int, int>& nodes) : m_nodes(nodes) {}
    map<int, int> &getNodes() const { return m_nodes; }
};

class AndGate : Gate
{
private:
    int m_inA;
    int m_inB;
    int m_out;

public:
    AndGate(int inA, int inB, int out, map<int, int>& nodes) : Gate(nodes), m_inA(inA), m_inB(inB), m_out(out) {}
    
    int evaluate()
    {
        int aState = getNodes()[m_inA];
        int bState = getNodes()[m_inB];
        int result = -1;
        if (aState == -1 || bState == -1) { return -1; }

        if (aState == 1)
        {
            if (bState == 1) { result = 1; }
            else { result = 0; }
        }
        else
        {
            if (bState == 1) { result = 0; }
            else { result = 0; }
        }

        getNodes()[m_out] = result;
        return result;
    }

    void print() const
    {
        cout << "AND\t" << m_inA << "\t" << m_inB << "\t" << m_out;
    }
};

class OrGate : Gate
{
private:
    int m_inA;
    int m_inB;
    int m_out;

public:
    OrGate(int inA, int inB, int out, map<int, int>& nodes) : Gate(nodes), m_inA(inA), m_inB(inB), m_out(out) {}

    int evaluate()
    {
        int aState = getNodes()[m_inA];
        int bState = getNodes()[m_inB];
        int result = -1;
        if (aState == -1 || bState == -1) { return -1; }

        if (aState == 1)
        {
            if (bState == 1) { result = 1; }
            else { result = 1; }
        }
        else
        {
            if (bState == 1) { result = 1; }
            else { result = 0; }
        }

        getNodes()[m_out] = result;
        return result;
    }

    void print() const
    {
        cout << "OR\t" << m_inA << "\t" << m_inB << "\t" << m_out;
    }
};

class XorGate : Gate
{
private:
    int m_inA;
    int m_inB;
    int m_out;

public:
    XorGate(int inA, int inB, int out, map<int, int>& nodes) : Gate(nodes), m_inA(inA), m_inB(inB), m_out(out) {}

    int evaluate()
    {
        int aState = getNodes()[m_inA];
        int bState = getNodes()[m_inB];
        int result = -1;
        if (aState == -1 || bState == -1) { return -1; }

        if (aState == 1)
        {
            if (bState == 1) { result = 0; }
            else { result = 1; }
        }
        else
        {
            if (bState == 1) { result = 1; }
            else { result = 0; }
        }

        getNodes()[m_out] = result;
        return result;
    }

    void print() const
    {
        cout << "XOR\t" << m_inA << "\t" << m_inB << "\t" << m_out;
    }
};

class NotGate : Gate
{
private:
    int m_inA;
    int m_out;

public:
    NotGate(int inA, int out, map<int, int>& nodes) : Gate(nodes), m_inA(inA), m_out(out) {}

    int evaluate()
    {
        int aState = getNodes()[m_inA];
        int result = -1;
        if (aState == -1) { return -1; }

        if (aState == 1) { result = 0; }
        else { result = 1; }

        getNodes()[m_out] = result;
        return result;
    }

    void print() const
    {
        cout << "AND\t" << m_inA << "\t" << m_out;
    }
};

void printNodes(const map<int, int>& nodes)
{
    cout << "node\tstate" << endl;
    for (pair node : nodes)
    {  
        cout << node.first << '\t' << node.second;
    }
}

int main()
{

    vector< unique_ptr<Gate> > gates;
    map<int, int> nodes;
    while (1)
    {
        string type;
        cout << "Wprowadz typ bramki:\t";
        cin >> type;
        if (type == "end") { break; }
        else if (type == "and" || type == "or" || type == "xor")
        {
            int a;
            int b;
            cout << "\nWprowadz indeks pierwszego wejscia:\t";
            cin >> a;
            cout << "\nWprowadz indeks drugiego wejscia:\t";
            cin >> b;
        }
        else if (type == "not")
        {
            int a;
            cout << "\nWprowadz indeks wejscia:\t";
            cin >> a;
        }
        int out;
        cout << "\nWprowadz indeks wyjscia bramki:\t";
        cin >> out;
        if (type == "and")
        {
            gates.emplace_back(make_unique<AndGate>(a, b, out, nodes))
        }
        

    }
    
}

