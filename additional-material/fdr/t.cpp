#include <fdr/fdr.h>
#include <iostream>

int main(int argc, char** argv)
{
    FDR::library_init(&argc, &argv);

    try
    {
        FDR::Session session;
        session.load_file("phils8.csp");
        for (const std::shared_ptr<FDR::Assertions::Assertion>& assertion
                : session.assertions())
        {
            assertion->execute(nullptr);
            std::cout << assertion->to_string() << " "
                << (assertion->passed() ? "Passed" : "Failed");
        }
    }
    catch (const FDR::Error& error)
    {
        std::cout << error.what() << std::endl;
    }

    FDR::library_exit();

    return 0;
}

