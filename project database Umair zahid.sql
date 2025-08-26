CREATE DATABASE UniversityManagement;
USE UniversityManagement;

CREATE TABLE Departments (
    DeptID INT PRIMARY KEY AUTO_INCREMENT,
    DeptName VARCHAR(50) NOT NULL,
    Location VARCHAR(50)
);

CREATE TABLE Courses (
    CourseID INT PRIMARY KEY AUTO_INCREMENT,
    CourseName VARCHAR(50) NOT NULL,
    DeptID INT,
    Credits INT,
    FOREIGN KEY (DeptID) REFERENCES Departments(DeptID)
);

CREATE TABLE Students (
    StudentID INT PRIMARY KEY AUTO_INCREMENT,
    StudentName VARCHAR(50) NOT NULL,
    Age INT,
    Gender VARCHAR(10),
    DeptID INT,
    FOREIGN KEY (DeptID) REFERENCES Departments(DeptID)
);

CREATE TABLE Enrollments (
    EnrollmentID INT PRIMARY KEY AUTO_INCREMENT,
    StudentID INT,
    CourseID INT,
    EnrollmentDate DATE,
    FOREIGN KEY (StudentID) REFERENCES Students(StudentID),
    FOREIGN KEY (CourseID) REFERENCES Courses(CourseID)
);

INSERT INTO Departments (DeptName, Location) VALUES
('Computer Science', 'Building A'),
('Business Administration', 'Building B'),
('Electrical Engineering', 'Building C');

INSERT INTO Courses (CourseName, DeptID, Credits) VALUES
('Database Systems', 1, 3),
('Digital Marketing', 2, 3),
('Circuit Analysis', 3, 4),
('Data Structures', 1, 3);

INSERT INTO Students (StudentName, Age, Gender, DeptID) VALUES
('Ali Khan', 21, 'Male', 1),
('Ayesha Malik', 22, 'Female', 2),
('Omar Sheikh', 20, 'Male', 3),
('Sara Ali', 21, 'Female', 1);

INSERT INTO Enrollments (StudentID, CourseID, EnrollmentDate) VALUES
(1, 1, '2025-01-10'),
(1, 4, '2025-01-10'),
(2, 2, '2025-01-12'),
(3, 3, '2025-01-15'),
(4, 1, '2025-01-20');

SELECT s.StudentName, d.DeptName
FROM Students s
JOIN Departments d ON s.DeptID = d.DeptID;

SELECT c.CourseName
FROM Courses c
JOIN Departments d ON c.DeptID = d.DeptID
WHERE d.DeptName = 'Computer Science';

SELECT s.StudentName, c.CourseName, e.EnrollmentDate
FROM Enrollments e
JOIN Students s ON e.StudentID = s.StudentID
JOIN Courses c ON e.CourseID = c.CourseID;

SELECT d.DeptName, COUNT(s.StudentID) AS TotalStudents
FROM Departments d
LEFT JOIN Students s ON d.DeptID = s.DeptID
GROUP BY d.DeptName;
