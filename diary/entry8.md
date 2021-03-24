# Entry #8 (2021/03/23)

- A compound statement (also called a block, or block statement) is a group of
  zero or more statements that is treated by the compiler as if it were a single
  statement.
- As a reminder, a naming collision occurs when two identical identifiers are
  introduced into the same scope, and the compiler can’t disambiguate which one
  to use.
- Namespaces that you create for your own declarations are called user-defined
  namespaces.
- you can access a `namespace` by using the scope resolution operator `::`
- The scope resolution operator can also be used without any preceding namespace
  (eg. ::doSomething). In such a case, the identifier (e.g. doSomething) is looked
  for in the global namespace.
- It’s legal to declare namespace blocks in multiple locations (either across
  multiple files, or multiple places within the same file). All declarations
  within the namespace are considered part of the namespace.
- **Warning:** Do not add custom functionality to the `std` namespace.
- Namespaces can be nested inside other namespaces.
- Local variables have block scope, hence all variable names within a scope
  must be unique.
- Local variables also have automatic storage duration, i.e. A variable’s storage
  duration (usually just called duration) determines what rules govern when and
  how a variable will be created and destroyed. In most cases, a variable’s
  storage duration directly determines its lifetime.
- Local variables have no **linkage**: An identifier’s linkage determines whether
  other declarations of that name refer to the same object or not. Local variables
  have no linkage, which means that each declaration refers to a unique object.
- Advice: Variables should be defined in the most limited scope
- By convention, global variables are declared at the top of a file, below the
  includes, but above any code.
- Consider using a `g` or `g_` prefix for global variables to help differentiate
  them from local variables.
- Global variables have file scope and static duration, which means they are
  visible from the point of declaration until the end of the file in which they
  are declared.
- Because they are defined outside of a function, global variables are considered
  to be part of the global namespace.
- Shadowing of local variables should generally be avoided, as it can lead to
  inadvertent errors where the wrong variable is used or modified. Some compilers
  will issue a warning when a variable is shadowed.
