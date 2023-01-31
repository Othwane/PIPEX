
#include "../pipex.h"

int main(int argc, char **argv, char **envp)
{
    t_data *pipex;

    pipex = malloc(sizeof(t_data));

    if (argc != 5)
    {
        ft_printf("pipex: Incompatible arguments\n");
        exit(1);
    }
    if (pipe(pipex->tube) == -1)
    {
        ft_printf("pipex: Pipe Error\n");
        exit(1);
    }
    pipex->pid = fork();
    if (pipex->pid < 0)
    {
        ft_printf("pipex: Fork Error\n");
        exit(1);
    }
    else if (pipex->pid == 0)
    {
        pipex->f_in = open(argv[1], O_RDONLY);
        if (pipex->f_in == -1)
        {
           ft_printf("pipex: %s: No such file or directory\n", argv[1]);
            exit(1);
        }
        if (access(argv[1], F_OK) != 0)
        {
            ft_printf("pipex: %s: No such file or directory\n", argv[1]);
            exit(1);
        }
        if (access(argv[1], R_OK) != 0)
        {
            ft_printf("pipex: %s: Permition denied\n", argv[1]);
            exit(1);
        }
        childproc(pipex, argv, envp);
    }
    else
    {
        pipex->f_out = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0664);
        if (pipex->f_out == -1)
        {
            ft_printf("pipex: %s: failed to open file\n", argv[4]);
            exit(1);
        }
        if (access(argv[4], W_OK) < 0)
        {
            ft_printf("Pipex: %s: Permition denied\n", argv[4]);
            exit(1);
        }
        parentproc(pipex, argv, envp);
    }
}