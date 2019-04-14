#include <iostream>
#include <stack>

class command
{
public:
    virtual ~command() = default;
    virtual void execute() = 0;
};

class revertable
{
public:
    virtual ~revertable() = default;
    virtual void undo() = 0;
};

class undoable_command : public command, public revertable
{
};

class command_type1 : public undoable_command
{
private:
    int id;

public:
    command_type1(int i) : id(i) {}
    void execute()
    {
        std::cout << "execute command of type 1 " << id << std::endl;
    }

    void undo()
    {
        std::cout << "undo command of type 1 " << id << std::endl;
    }
};

class command_type2 : public undoable_command
{
private:
    int id;

public:
    command_type2(int i) : id(i) {}
    void execute()
    {
        std::cout << "execute command of type 2 " << id << std::endl;
    }

    void undo()
    {
        std::cout << "undo command of type 2 " << id << std::endl;
    }
};

class receiver
{
private:
    std::stack<revertable *> command_history;

public:
    void accept_command(undoable_command *cmd)
    {
        cmd->execute();
        command_history.push(cmd);
    }
    void undo_last_command()
    {
        if (command_history.empty())
        {
            return;
        }
        command_history.top()->undo();
        command_history.pop();
    }
};

int main()
{
    receiver receiver;
    undoable_command *p1 = new command_type1(101);
    undoable_command *p2 = new command_type2(102);
    undoable_command *p3 = new command_type1(201);
    receiver.accept_command(p1);
    receiver.accept_command(p2);
    receiver.accept_command(p3);
    receiver.undo_last_command();
    receiver.undo_last_command();
    receiver.undo_last_command();

    delete p1;
    delete p2;
    delete p3;

    return 0;
}
