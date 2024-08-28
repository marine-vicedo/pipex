# Pipex Project
### Overview
The Pipex project involves exploring and understanding the details of a specific UNIX mechanism by implementing it through programming. The objective is to replicate the behavior of a shell pipeline using C.

### Project Requirements
- Allowed External Functions: open, close, read, write, malloc, free, perror, strerror, access, dup, dup2, execve, exit, fork, pipe, unlink, wait, waitpid, ft_printf or equivalent custom-coded versions

### Program Execution:

`./pipex file1 cmd1 cmd2 file2`

This should behave the same as the following shell command:

`< file1 cmd1 | cmd2 > file2`

Example Usage:

`$> ./pipex infile "ls -l" "wc -l" outfile`

Should be identical to:

`< infile ls -l | wc -l > outfile`
