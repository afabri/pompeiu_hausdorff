// Given two triangle soups (VA,FA) and (VB,FB), it calculates an upper bound for the Pompeiu-Hausdorff distance from each triangle from A to mesh B, as decribed in "2018 - Kang et al. - Fast and robust Hausdorff distance computation from triangle mesh to quad mesh in near-zero cases"

// Input:
// VA: #vertices(A) x 3 Eigen matrix containing x, y z coordinates of each vertex
// FA: #faces(A) x 3 Eigen matrix containing vertex indices of each face
// VB: #vertices(B) x 3 Eigen matrix containing x, y z coordinates of each vertex
// FB: #faces(B) x 3 Eigen matrix containing vertex indices of each face
// DV: #vertices(A) x 1 Eigen matrix containing distances from each vertex of A to B
// I: #vertices(A) x 1 Eigen vector containing indices of faces from B to which points from A are projected

// Output:
// u: #faces(A) x 1 Eigen vector containing the upper bound for the Pompeiu-Hausdorff distance from each triangle on A to mesh B

#include <stdio.h>
#include <iostream>
#include <time.h>
#include <cfloat>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <CGAL/Simple_cartesian.h>
#include <CGAL/squared_distance_3.h>
#include "kang_intersect_edge_and_bisector.h"
#include <sys/time.h>

using namespace std;

int kang_upper_bound(const Eigen::MatrixXd & VA, const Eigen::MatrixXi & FA, const Eigen::MatrixXd & VB, const Eigen::MatrixXi & FB, const Eigen::MatrixXd & DV, const Eigen::VectorXi & I, Eigen::VectorXd & u);
