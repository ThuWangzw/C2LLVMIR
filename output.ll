; ModuleID = 'c model'
source_filename = "c model"

define i32 @main() {
entry:
  %0 = alloca i32
  store i32 21, i32* %0
  %1 = alloca i32
  store i32 14, i32* %1
  %arrayPtr = load i32, i32* %0
  %2 = load i32, i32* %0
  %arrayPtr1 = load i32, i32* %1
  %3 = load i32, i32* %1
  %addtmp = add i32 %2, %3
  ret i32 %addtmp
  ret i32 0
}