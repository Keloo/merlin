#pragma once

namespace Component {
    class Command {
    public:
        virtual ~Command();
        virtual void execute() = 0;
    };
}