
#include "../pipex.h"

int main(int argc, char **argv, char **envp)
{
    t_data *pipex;

    if (argc != 5)
    {
        ft_printf("Pipex: Incompatible arguments ");
        exit(1);
    }
    if (pipe(pipex->tube) == -1)
    {
        ft_printf("Pipex: Pipe Error");
        exit(1);
    }
    pipex->pid = fork();
    if (pipex->pid < 0)
    {
        ft_printf("Pipex: Fork Error");
        exit(1);
    }
    else if (pipex->pid == 0)
    {
        pipex->f_in = open(argv[1], O_RDONLY);
        if (pipex->f_in == -1)
        {
            ft_printf("Pipex: %s: Failed to open", argv[1]);
            exit(1);
        }
        if (access(argv[1], F_OK) != 0)
        {
            ft_printf("Pipex: : %s: No such file or directory", argv[1]);
            exit(1);
        }
        if (access(argv[1], R_OK) != 0)
        {
            ft_printf("Pipex: %s: Permition denied", argv[1]);
            exit(1);
        }
        childproc(pipex, argv, envp);
    }
    else
    {
        pipex->f_out = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0664);
        if (pipex->f_out == -1)
        {
            ft_printf("Pipex: : %s: failed to open file", argv[4]);
            exit(1);
        }
        if (access(argv[4], W_OK) != 0)
        {
            ft_printf("Pipex: %s: Permition denied", argv[4]);
            exit(1);
        }
        parentproc(pipex, argv, envp);
    }
}