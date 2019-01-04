; ModuleID = 'c model'
source_filename = "c model"

define i32 @f(i32 %a) {
entry:
  %0 = alloca i32
  store i32 1, i32* %0
  ret i32 0
  ret i32 0
}

define i32 @main() {
entry:
  %0 = alloca i32
  store i32 1, i32* %0
  %arrayPtr = load i32, i32* %0
  %1 = load i32, i32* %0
  %cmptmp = icmp sgt i32 %1, 1
  %ifcond = icmp ne i1 %cmptmp, false
  br i1 %ifcond, label %then, label %else

then:                                             ; preds = %entry
                                                  ; No predecessors!
  ret i32 1
  br label %ifcont

else:                                             ; preds = %entry
  br label %ifcont

ifcont:                                           ; preds = %else, %2
  %iftmp = phi i32 [ 1, %2 ], [ -1, %else ]
  %arrayPtr1 = load i32, i32* %0
  %3 = load i32, i32* %0
  ret i32 %3
  ret i32 0
}
