// t_data  algorithm(t_data data)
// {
//     int         l;
//     t_list      *small;
//     t_list      *current;
//     double      distance;
//     double      half_size;

//     current = NULL;
//     l = ft_lstsize(data.stack_a);
//     current = data.stack_a;
//     small = data.stack_a;
//     distance = 0;
//     half_size = (l / 2);
//     while(current->content != small->content)
//     {
//         distance++;
//         current = current->next;
//     }
//     printf("\n\ndis: %f | h_s: %f\n\n", distance, half_size);
//     if ((check_if_sorted(data.stack_a) == 1) && (ft_lstsize(data.stack_a) == l))
//         return (data);
//     while (ft_lstsize(data.stack_a) != 1)
//     {
//         // if (distance == 1)
//         // {
//         //     data = swap_a(data);
//         // }  
//         if ((distance > half_size) && distance)
//         {
//             data = reverse_rotate_a(data);
//         }
//         else if (((distance < half_size) || (distance == half_size)) && distance)
//         {
//             data = rotate_a(data);
//         }
//         if((data.stack_a)->content == (small->content))
//         {
//             data = push_b(data);
//             small = small->next;
//             distance = 0;
//             current = data.stack_a;
//             while(current->content != small->content)
//             {
//                 distance++;
//                 current = current->next;
//             }
//             printf("\n\ndis: %f | h_s: %f\n\n", distance, half_size);
//         }
//     }
//     // data = empty_b(data, ft_lstsize(data.stack_b));
//     return (data);
// }

// t_data  old_ptoto_algorithm(t_data data)
// {
//     int         l;
//     t_list      *small;
//     t_list      *current;
//     double      distance;
//     double      half_size;

//     current = NULL;
//     l = ft_lstsize(data.stack_a);
//     current = data.stack_a;
//     small = smallest(data.stack_a);
//     distance = 0;
//     half_size = (l / 2);
//     while(current->content != small->content)
//     {
//         distance++;
//         current = current->next;
//     }
//     printf("\n\ndis: %f | h_s: %f\n\n", distance, half_size);
//     if ((check_if_sorted(data.stack_a) == 1) && (ft_lstsize(data.stack_a) == l))
//         return (data);
//     while (ft_lstsize(data.stack_a) != 1)
//     {
//         if (distance == 1)
//         {
//             data = swap_a(data);
//         }  
//         if ((distance > half_size) && distance)
//         {
//             data = reverse_rotate_a(data);
//         }
//         else if (((distance < half_size) || (distance == half_size)) && distance)
//         {
//             data = rotate_a(data);
//         }
//         if((data.stack_a)->content == (small->content))
//         {
//             data = push_b(data);
//             small = smallest(data.stack_a);
//             distance = 0;
//             current = data.stack_a;
//             half_size = (ft_lstsize(current) / 2);
//             while(current->content != small->content)
//             {
//                 distance++;
//                 current = current->next;
//             }
//             printf("\n\ndis: %f | h_s: %f\n\n", distance, half_size);
//         }
//     }
//     // data = empty_b(data, ft_lstsize(data.stack_b));
//     return (data);
// }