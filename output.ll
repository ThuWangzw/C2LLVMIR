; ModuleID = 'c model'
source_filename = "c model"

@a = common global i32 0, align 4
@b = common global i32 0, align 4
@c = common global i32 0, align 4

define i32 @main() {
entry:
  store i32 1, i32* @a
  store i32 2, i32* @b
  %arrayPtr = load i32, i32* @a
  %0 = load i32, i32* @a
  %arrayPtr1 = load i32, i32* @b
  %1 = load i32, i32* @b
  %addtmp = add i32 %0, %1
  store i32 %addtmp, i32* @c
  ret i32 0
  ret i32 0
}

