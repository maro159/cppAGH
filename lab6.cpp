#include <iostream>
#include <map>
#include <vector>
#include <memory>


using namespace std;

class IGate
{
    public:
        virtual int evaluate()  = 0;
        virtual void print() const = 0;
        virtual ~IGate() = default;

};

class Gate : public IGate
{
private:
    map<int, int> &m_nodes;
public:
    Gate(map<int, int>& nodes) : m_nodes(nodes) {}
    map<int, int> &getNodes() { return m_nodes; }
};

class AndGate : public Gate
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
        cout << "AND\t" << "WE: " << m_inA << "\t" << "WE: " << m_inB << "\t" << "WY: " << m_out << endl;
    }
};

class OrGate : public Gate
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
        cout << "OR\t" << "WE: " << m_inA << "\t" << "WE: " << m_inB << "\t" << "WY: " << m_out << endl;
    }
};

class XorGate : public Gate
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
        cout << "XOR\t" << "WE: " << m_inA << "\t" << "WE: " << m_inB << "\t" << "WY: " << m_out << endl;
    }
};

class NotGate : public Gate
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
        cout << "NOT\t" << "WE: " << m_inA << "\t" << "WY: " << m_out << endl;
    }
};

void printNodes(const map<int, int>& nodes)
{
    cout << "\nnode\tstate" << endl;
    for (pair node : nodes)
    {  
        cout << node.first << '\t' << node.second << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "pl_PL"); setlocale(LC_ALL, "polish");


    vector< unique_ptr<Gate> > gates;
    map<int, int> nodes;
    while (1) // wprowadzanie bramki
    {
        int a;
        int b;
        int out;
        string type;
        cout << "WprowadŸ typ bramki:\t";
        cin >> type;
        if (type == "end") { break; }


        else if (type == "and" || type == "or" || type == "xor")
        {

            cout << "\nWprowadz indeks pierwszego wejscia:\t";
            cin >> a;
            cout << "\nWprowadz indeks drugiego wejscia:\t";
            cin >> b;
        }
        else if (type == "not")
        {
            cout << "\nWprowadz indeks wejscia:\t";
            cin >> a;
        }
        cout << "\nWprowadz indeks wyjscia bramki:\t";
        cin >> out;
        if (type == "and")
        {
            gates.emplace_back(make_unique<AndGate>(a, b, out, nodes));
        }
        else if (type == "or")
        {
            gates.emplace_back(make_unique<OrGate>(a, b, out, nodes));
        }
        else if (type == "xor")
        {
            gates.emplace_back(make_unique<XorGate>(a, b, out, nodes));
        }
        else if (type == "not")
        {
            gates.emplace_back(make_unique<NotGate>(a, out, nodes));
        }

        nodes[a] = -1;
        if (type != "not") nodes[b] = -1;
        nodes[out] = -1;
    }
    
    while (1)
    {
        int node= -1;
        int state = -1;
        cout << "Wprowadz indeks wêz³a:\t";
        cin >> node;

        if (node == -1) break;
        else
        {
            cout << "Wprowadz stan wêz³a" << node << " ->\t";
            cin >> state;
        }
        nodes[node] = state;
    }

    int status;
    do
    {
        status = 0;
        cout << endl;
        for (auto& gate : gates)
        {
            if (gate->evaluate() == -1) status = -1;
            gate->print();
        }
    } while (status != 0);

    printNodes(nodes);
}

