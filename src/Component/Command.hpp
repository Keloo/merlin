#pragma once

namespace Component {
    class Command {
    public:
        virtual ~Command();
        virtual void execute() = 0;
        virtual void execute(double, double) = 0; // @todo (ugly) find a way to remove it
    };
}