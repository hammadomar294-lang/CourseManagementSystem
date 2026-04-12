# Course Management System

## نظام إدارة تسجيل المقررات الدراسية باستخدام لغة C++ (Console-Based System)

### Team Leader and System Architect

Omar

### Team Members

Abd_elrahman
Amira
Basmala
Ibrahem
Sabry
Yassin

---

## وصف المشروع

هذا المشروع عبارة عن نظام إدارة تسجيل مقررات دراسية يعمل من خلال واجهة Console باستخدام لغة C++. يهدف النظام إلى محاكاة بيئة تسجيل أكاديمية مصغرة تسمح للطلاب بالتسجيل في المقررات، وتمكن المشرف (Admin) من إدارة المقررات والطلاب والدرجات داخل النظام.

يعتمد النظام على أسلوب Menu-driven architecture مع دعم تعدد الأدوار داخل النظام:

Student Role
Admin Role

كما يعتمد النظام على File-based persistence لحفظ البيانات واسترجاعها بين جلسات التشغيل المختلفة.

---

## أهداف المشروع

يهدف المشروع إلى تطبيق المفاهيم التالية عملياً:

تصميم نظام متعدد المستخدمين (Multi-role system)
إدارة العلاقات بين الكيانات (Relationship Modeling)
التعامل مع الملفات باستخدام لغة C++
تصميم نظام قائم على القوائم (Menu-driven system)
إدارة سلامة البيانات داخل النظام (Data Integrity Handling)
محاكاة قاعدة بيانات باستخدام Arrays و Text Files

---

## مكونات النظام الأساسية

يعتمد النظام على أربع كيانات رئيسية:

### Student

يحتوي على:

Student ID
Name
Password
Level
Number of registered courses

---

### Course

يحتوي على:

Course ID
Course Name
Instructor Name
Credit Hours
Max Capacity
Current Enrolled Students
Day
Time

---

### Admin

يحتوي على:

Admin ID
Name
Password

---

### StudentCourse (Relationship Table)

يستخدم هذا الجدول لإدارة العلاقة من النوع Many-to-Many بين الطلاب والمقررات الدراسية.

ويحتوي على:

Student ID
Course ID
Grade

ويمثل هذا الجدول محاكاة لفكرة Relational Database Join Table داخل نظام Console.

---

## وظائف الطالب داخل النظام

يمكن للطالب تنفيذ العمليات التالية:

إنشاء حساب جديد
تسجيل الدخول
عرض المقررات المتاحة
التسجيل في مقرر
حذف مقرر
عرض المقررات المسجلة
عرض الدرجات

---

## وظائف المشرف داخل النظام

يمكن للمشرف تنفيذ العمليات التالية:

إضافة مقرر جديد
حذف مقرر
عرض جميع الطلاب
عرض جميع المقررات
عرض مقررات طالب معين
عرض طلاب مقرر معين
عرض درجات طالب
تعديل درجات طالب

---

## نظام حفظ البيانات

يعتمد النظام على ملفات نصية لحفظ البيانات واسترجاعها:

students.txt
courses.txt
admins.txt
studentcourses.txt

يتم تحميل البيانات عند بدء تشغيل البرنامج، ويتم حفظ البيانات تلقائياً عند إغلاق البرنامج.

---

## قواعد التحقق داخل النظام

يطبق النظام مجموعة من قواعد التحقق لضمان سلامة البيانات:

عدم السماح بتسجيل أكثر من 10 مقررات للطالب
عدم تجاوز السعة القصوى للمقرر
منع تكرار أسماء المستخدمين
منع التسجيل المكرر في نفس المقرر
حذف العلاقات المرتبطة بالمقرر عند حذف مقرر

---

## الهيكل المعماري للنظام

يعتمد النظام على مجموعة من المكونات الأساسية:

Menu-driven navigation system
Role-based access control
Relationship table modeling
ID auto-generation system
File persistence simulation

ويمثل هذا التصميم نموذجاً مبسطاً للأنظمة المستخدمة في:

Academic Registration Systems
Inventory Systems
ERP-style Console Applications

---

## هيكل المشروع

يتكون المشروع من الملفات التالية:

source/
abd_elrahman.cpp
amira.cpp
basmala.cpp
ibrahem.cpp
sabry.cpp
yassin.cpp

main.cpp
Makefile
informationfiles/

تم تقسيم العمل بين أعضاء الفريق لتنفيذ أجزاء مختلفة من النظام تحت إشراف Team Leader and System Architect.

---

## مسؤوليات قائد الفريق

قام قائد الفريق بتنفيذ المهام التالية:

تصميم الهيكل المعماري للنظام
تصميم منطق العلاقات بين الكيانات
تنفيذ طبقة File Persistence
تصميم نظام توليد المعرفات IDs
بناء Menu Routing Structure
توزيع المهام على أعضاء الفريق
مراجعة تكامل النظام النهائي

---

## الهدف التعليمي من المشروع

يهدف المشروع إلى تطبيق مجموعة من المفاهيم الأساسية في البرمجة:

Structured Programming
Data Modeling
File Handling
Relationship Management
Menu-driven System Design
System Integrity Maintenance


---

## Author

Omar
Team Leader and System Architect
